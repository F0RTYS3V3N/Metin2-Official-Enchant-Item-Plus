//Find
		void		AddAttribute(BYTE bType, short sValue);

///Add
#if defined(__BL_SELECT_ATTR__)
		void		GetSelectAttr(TPlayerItemAttribute (&arr)[ITEM_ATTRIBUTE_MAX_NUM]);
#endif