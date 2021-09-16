//Find
		bool SendSelectItemPacket(DWORD dwItemPos);

///Add
#if defined(__BL_SELECT_ATTR__)
		bool RecvSelectAttr();
		bool SendChagedItemAttributePacket(const bool bNew, const TItemPos& pos);
#endif