//Find
		int				GetSyncHackCount() { return m_iSyncHackCount; }

///Add
#if defined(__BL_SELECT_ATTR__)
	public:
		void						SelectAttr(LPITEM material, LPITEM item);
		void						SelectAttrResult(const bool bNew, const TItemPos& pos);
		bool						IsSelectAttr() const;
	private:
		struct SItemSelectAttr
		{
			DWORD					dwItemID;
			TPlayerItemAttribute	Attr[ITEM_ATTRIBUTE_MAX_NUM];
		} m_ItemSelectAttr;
#endif