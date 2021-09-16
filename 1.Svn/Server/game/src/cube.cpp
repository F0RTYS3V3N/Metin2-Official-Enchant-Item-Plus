//Find
	if ( ch->GetExchange() || ch->GetMyShop() || ch->GetShopOwner() || ch->IsOpenSafebox() || ch->IsCubeOpen() )

///Change
	if ( ch->GetExchange() || ch->GetMyShop() || ch->GetShopOwner() || ch->IsOpenSafebox() || ch->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| ch->IsSelectAttr()
#endif
	)