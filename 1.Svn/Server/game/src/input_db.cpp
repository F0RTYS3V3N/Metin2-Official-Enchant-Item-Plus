//Find
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| ch->IsSelectAttr()
#endif
	)