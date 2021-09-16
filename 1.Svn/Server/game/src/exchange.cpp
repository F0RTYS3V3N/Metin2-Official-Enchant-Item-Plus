//Find
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen() )

///Change
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| IsSelectAttr()
#endif
	)

//Find
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen() )

///Change
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| victim->IsSelectAttr()
#endif
	)