//Find
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
						|| ch->IsSelectAttr()
#endif
					)

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| ch->IsSelectAttr()
#endif
	)

//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(__BL_SELECT_ATTR__)
void CInputMain::ItemSelectAttr(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCGItemSelectAttr* p = reinterpret_cast<const TPacketCGItemSelectAttr*>(c_pData);
	
	ch->SelectAttrResult(p->bNew, p->pItemPos);
}
#endif

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| ch->IsSelectAttr()
#endif
	)

//Find
		case HEADER_CG_MALL_CHECKOUT:
			SafeboxCheckout(ch, c_pData, true);
			break;

#if defined(__BL_SELECT_ATTR__)
		case HEADER_CG_ITEM_SELECT_ATTR:
			ItemSelectAttr(ch, c_pData);
			break;
#endif