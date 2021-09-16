//Find
void CPythonPlayer::GetItemAttribute(TItemPos Cell, DWORD dwAttrSlotIndex, BYTE * pbyType, short * psValue)
{
	...
}

///Add
#if defined(__BL_SELECT_ATTR__)
void CPythonPlayer::GetItemChangedAttribute(DWORD dwAttrSlotIndex, BYTE* pbyType, short* psValue)
{
	*pbyType = 0;
	*psValue = 0;

	if (dwAttrSlotIndex >= ITEM_ATTRIBUTE_SLOT_MAX_NUM)
		return;

	*pbyType = m_SelectAttrArr[dwAttrSlotIndex].bType;
	*psValue = m_SelectAttrArr[dwAttrSlotIndex].sValue;
}

void CPythonPlayer::SetSelectAttr(const TPlayerItemAttribute* attr)
{
	memcpy(m_SelectAttrArr, attr, sizeof(m_SelectAttrArr));
}
#endif

//Find
	memset(m_adwEffect, 0, sizeof(m_adwEffect));

///Add
#if defined(__BL_SELECT_ATTR__)
	memset(m_SelectAttrArr, 0, sizeof m_SelectAttrArr);
#endif