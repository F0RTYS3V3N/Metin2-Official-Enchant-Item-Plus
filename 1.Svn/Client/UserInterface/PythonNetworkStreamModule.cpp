//Find
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_SELECT_ATTR__)
PyObject* netSendChagedItemAttributePacket(PyObject* poSelf, PyObject* poArgs)
{
	bool bNew;
	if (!PyTuple_GetBoolean(poArgs, 0, &bNew))
		return Py_BuildException();

	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 1, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 2, &Cell.cell))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendChagedItemAttributePacket(bNew, Cell);

	return Py_BuildNone();
}
#endif

//Find
		{ "SendSelectItemPacket",					netSendSelectItemPacket,					METH_VARARGS },

///Add
#if defined(__BL_SELECT_ATTR__)
		{ "SendChagedItemAttributePacket",			netSendChagedItemAttributePacket,			METH_VARARGS },
#endif