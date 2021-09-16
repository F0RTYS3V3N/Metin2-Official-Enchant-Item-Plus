//Find
			Set(HEADER_GC_DAMAGE_INFO, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDamageInfo), STATIC_SIZE_PACKET));

///Add
#if defined(__BL_SELECT_ATTR__)
			Set(HEADER_GC_ITEM_SELECT_ATTR, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCItemSelectAttr), STATIC_SIZE_PACKET));
#endif