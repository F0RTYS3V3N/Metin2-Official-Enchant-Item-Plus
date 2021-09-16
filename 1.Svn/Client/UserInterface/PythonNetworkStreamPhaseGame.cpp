//Find
			case HEADER_GC_CHANNEL:
				ret = RecvChannelPacket();
				break;

///Add
#if defined(__BL_SELECT_ATTR__)
			case HEADER_GC_ITEM_SELECT_ATTR:
				ret = RecvSelectAttr();
				break;
#endif

//Find
bool CPythonNetworkStream::RecvMotionPacket()
{
	...
}

///Add
#if defined(__BL_SELECT_ATTR__)
bool CPythonNetworkStream::RecvSelectAttr()
{
	TPacketGCItemSelectAttr p;

	if (!Recv(sizeof(p), &p))
		return false;

	CPythonPlayer::Instance().SetSelectAttr(p.aAttr);
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OpenSelectAttrDialog", Py_BuildValue("(ii)", p.pItemPos.window_type, p.pItemPos.cell));

	return true;
}

bool CPythonNetworkStream::SendChagedItemAttributePacket(const bool bNew, const TItemPos& pos)
{
	TPacketCGItemSelectAttr p;
	p.bHeader = HEADER_CG_ITEM_SELECT_ATTR;
	p.bNew = bNew;
	p.pItemPos = pos;

	if (!Send(sizeof(p), &p))
	{
		Tracef("SendChagedItemAttributePacket Error\n");
		return false;
	}

	return SendSequence();
}
#endif