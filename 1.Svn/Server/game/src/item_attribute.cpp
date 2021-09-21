///Add
#if defined(__BL_SELECT_ATTR__)
#include "utils.h"
void CItem::GetSelectAttr(TPlayerItemAttribute(&arr)[ITEM_ATTRIBUTE_MAX_NUM])
{
	auto __GetAttributeCount = [&arr]() -> int
	{
		auto c = std::count_if(std::begin(arr), std::end(arr), 
			[](const TPlayerItemAttribute& _attr) { return _attr.bType != 0 && _attr.sValue != 0; });

		return c;
	};

	auto __HasAttr = [this, &arr](const BYTE bApply) -> bool
	{
		if (m_pProto)
		{
			for (size_t i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
				if (m_pProto->aApplies[i].bType == bApply)
					return true;
		}

		for (size_t i = 0; i < MAX_NORM_ATTR_NUM; ++i)
			if (arr[i].bType == bApply)
				return true;

		return false;
	};

	auto __PutAttributeWithLevel = [this, &__HasAttr, &__GetAttributeCount, &arr](BYTE bLevel) -> void
	{
		const int iAttributeSet = GetAttributeSetIndex();

		if (iAttributeSet < 0)
			return;

		if (bLevel > ITEM_ATTRIBUTE_MAX_LEVEL)
			return;

		std::vector<int> avail;

		int total = 0;

		for (size_t i = 0; i < MAX_APPLY_NUM; ++i)
		{
			const TItemAttrTable& r = g_map_itemAttr[i];

			if (r.bMaxLevelBySet[iAttributeSet] && !__HasAttr(i))
			{
				avail.push_back(i);
				total += r.dwProb;
			}
		}

		unsigned int prob = number(1, total);
		int attr_idx = APPLY_NONE;

		for (size_t i = 0; i < avail.size(); ++i)
		{
			const TItemAttrTable& r = g_map_itemAttr[avail[i]];

			if (prob <= r.dwProb)
			{
				attr_idx = avail[i];
				break;
			}

			prob -= r.dwProb;
		}

		if (!attr_idx)
		{
			sys_err("Cannot put item attribute %d %d", iAttributeSet, bLevel);
			return;
		}

		const TItemAttrTable& r = g_map_itemAttr[attr_idx];

		if (bLevel > r.bMaxLevelBySet[iAttributeSet])
			bLevel = r.bMaxLevelBySet[iAttributeSet];

		const long lVal = r.lValues[MIN(4, bLevel - 1)];
		arr[__GetAttributeCount()] = { static_cast<BYTE>(attr_idx), static_cast<short>(lVal) };
	};

	if (m_pProto && m_pProto->sAddonType)
	{
		int iSkillBonus = MINMAX(-30, static_cast<int>(gauss_random(0, 5) + 0.5f), 30);
		int iNormalHitBonus = 0;
		if (abs(iSkillBonus) <= 20)
			iNormalHitBonus = -2 * iSkillBonus + abs(number(-8, 8) + number(-8, 8)) + number(1, 4);
		else
			iNormalHitBonus = -2 * iSkillBonus + number(1, 5);

		arr[__GetAttributeCount()] = { static_cast<BYTE>(APPLY_NORMAL_HIT_DAMAGE_BONUS), static_cast<short>(iNormalHitBonus) };
		arr[__GetAttributeCount()] = { static_cast<BYTE>(APPLY_SKILL_DAMAGE_BONUS), static_cast<short>(iSkillBonus) };
	}

	static constexpr BYTE aiAttrPercentTable[ITEM_ATTRIBUTE_MAX_LEVEL] = { 0, 10, 40, 35, 15 };
	for (BYTE c = __GetAttributeCount(); c < GetAttributeCount(); c++)
	{
		int iAttrLevelPercent = number(1, 100);
		size_t i;

		for (i = 0; i < ITEM_ATTRIBUTE_MAX_LEVEL; ++i)
		{
			if (iAttrLevelPercent <= aiAttrPercentTable[i])
				break;

			iAttrLevelPercent -= aiAttrPercentTable[i];
		}

		__PutAttributeWithLevel(i + 1);
	}

	std::copy(std::begin(m_aAttr) + MAX_NORM_ATTR_NUM, std::end(m_aAttr), std::begin(arr) + MAX_NORM_ATTR_NUM);
}
#endif