//Find
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen())

///Change
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen()
#if defined(__BL_SELECT_ATTR__)
		|| pkChr->IsSelectAttr()
#endif
	)