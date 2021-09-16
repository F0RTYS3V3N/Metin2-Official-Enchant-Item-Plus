///Add
#if defined(__BL_SELECT_ATTR__)
PyObject* playerGetItemChangedAttribute(PyObject* poSelf, PyObject* poArgs)
{
	int iAttributeSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iAttributeSlotIndex))
		return Py_BuildException();

	BYTE byType;
	short sValue;
	CPythonPlayer::Instance().GetItemChangedAttribute(iAttributeSlotIndex, &byType, &sValue);

	return Py_BuildValue("ii", byType, sValue);
}
#endif

//Find
		{ "SendDragonSoulRefine",		playerSendDragonSoulRefine,			METH_VARARGS },

///Add
#if defined(__BL_SELECT_ATTR__)
		{ "GetItemChangedAttribute",			playerGetItemChangedAttribute,				METH_VARARGS },
#endif