//Find
	memset(&m_tvLastSyncTime, 0, sizeof(m_tvLastSyncTime));

///Add
#if defined(__BL_SELECT_ATTR__)
	memset(&m_ItemSelectAttr, 0, sizeof(m_ItemSelectAttr));
#endif

//Find
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

///Change
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
						|| IsSelectAttr()
#endif
					)

//Find
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

///Change
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
						|| pkChrCauser->IsSelectAttr()
#endif
					)

//Find
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

///Change
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
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

//Find
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
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