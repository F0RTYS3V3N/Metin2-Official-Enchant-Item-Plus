//Find
	if (IsCubeOpen() || NULL != DragonSoul_RefineWindow_GetOpener())
		return false;

///Add
#if defined(__BL_SELECT_ATTR__)
	if (IsSelectAttr())
		return false;
#endif

//Find
					case USE_ADD_ATTRIBUTE2:

///Add
#if defined(__BL_SELECT_ATTR__)
					case USE_SELECT_ATTRIBUTE:
#endif

//Find
							if (ITEM_COSTUME == item2->GetType())
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
								return false;
							}

///Change
#if defined(__BL_SELECT_ATTR__)
							if (ITEM_COSTUME == item2->GetType() && item->GetSubType() != USE_SELECT_ATTRIBUTE)
#else
							if (ITEM_COSTUME == item2->GetType())
#endif
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
								return false;
							}

//Find
								case USE_CLEAN_SOCKET:
									{
										...
									}
									break;

///Add
#if defined(__BL_SELECT_ATTR__)
								case USE_SELECT_ATTRIBUTE:
									SelectAttr(item, item2);
								break;
#endif

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
			|| IsSelectAttr()
#endif
		)

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
			|| IsSelectAttr()
#endif
		)

///Add New Funcs
#if defined(__BL_SELECT_ATTR__)
void CHARACTER::SelectAttr(LPITEM material, LPITEM item)
{
	const LPDESC d = GetDesc();
	if (d == nullptr)
		return;

	if (IsSelectAttr() || GetExchange() || IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen())
	{
		ChatPacket(CHAT_TYPE_INFO, "You have to close other windows.");
		return;
	}

	if (item->GetAttributeSetIndex() == -1)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
		return;
	}
	
	if (item->GetAttributeCount() < 1)
		return;
	
	const TItemPos pos(item->GetWindow(), item->GetCell());
	
	if (pos.IsDefaultInventoryPosition() == false)
		return;

	m_ItemSelectAttr.dwItemID = item->GetID();
	item->GetSelectAttr(m_ItemSelectAttr.Attr);
	
	TPacketGCItemSelectAttr p;
	p.bHeader = HEADER_GC_ITEM_SELECT_ATTR;
	p.pItemPos = pos;
	std::copy(std::begin(m_ItemSelectAttr.Attr), std::end(m_ItemSelectAttr.Attr), std::begin(p.aAttr));
	d->Packet(&p, sizeof p);

	material->SetCount(material->GetCount() - 1);
}

void CHARACTER::SelectAttrResult(const bool bNew, const TItemPos& pos)
{
	if (IsSelectAttr() == false)
		return;
	
	if (bNew)
	{
		const LPITEM item = GetItem(pos);
		if (item && item->GetID() == m_ItemSelectAttr.dwItemID)
		{
			item->SetAttributes(m_ItemSelectAttr.Attr);
			item->UpdatePacket();
			ChatPacket(CHAT_TYPE_INFO, "You have changed the upgrade.");
		}
	}

	memset(&m_ItemSelectAttr, 0, sizeof m_ItemSelectAttr);
}

bool CHARACTER::IsSelectAttr() const
{
	return m_ItemSelectAttr.dwItemID != 0;
}
#endif