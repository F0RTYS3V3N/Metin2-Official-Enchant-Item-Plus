//Find
	Set(HEADER_CG_GUILD, sizeof(TPacketCGGuild), "Guild", true);

///Add
#if defined(__BL_SELECT_ATTR__)
	Set(HEADER_CG_ITEM_SELECT_ATTR, sizeof(TPacketCGItemSelectAttr), "ItemSelectAttr", true);
#endif