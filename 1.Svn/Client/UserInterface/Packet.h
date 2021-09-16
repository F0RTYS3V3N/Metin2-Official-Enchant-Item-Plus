//Find
#ifdef __AUCTION__
	HEADER_CG_AUCTION_CMD							= 205,
#endif

///Add
#if defined(__BL_SELECT_ATTR__)
	HEADER_CG_ITEM_SELECT_ATTR = 227,
#endif

//Find
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,

///Add
#if defined(__BL_SELECT_ATTR__)
	HEADER_GC_ITEM_SELECT_ATTR = 227,
#endif

//Find
typedef struct packet_shop_update_item
{
	...
} TPacketGCShopUpdateItem;

///Add
#if defined(__BL_SELECT_ATTR__)
typedef struct packet_gc_item_select_attr
{
	BYTE					bHeader;
	TItemPos				pItemPos;
	TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TPacketGCItemSelectAttr;

typedef struct packet_cg_item_select_attr
{
	BYTE					bHeader;
	bool					bNew;
	TItemPos				pItemPos;
} TPacketCGItemSelectAttr;
#endif