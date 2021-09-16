//Find
		void	EndEmotionProcess();

///Add
#if defined(__BL_SELECT_ATTR__)
		void	GetItemChangedAttribute(DWORD dwAttrSlotIndex, BYTE* pbyType, short* psValue);
		void	SetSelectAttr(const TPlayerItemAttribute* attr);
#endif

//Find
		DWORD					m_adwEffect[EFFECT_NUM];

///Add
#if defined(__BL_SELECT_ATTR__)
		TPlayerItemAttribute	m_SelectAttrArr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
#endif