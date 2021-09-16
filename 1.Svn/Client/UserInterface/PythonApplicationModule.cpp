//Find
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	0);
#endif

///Add
#if defined(__BL_SELECT_ATTR__)
	PyModule_AddIntConstant(poModule, "BL_CHANGED_ATTR", true);
#else
	PyModule_AddIntConstant(poModule, "BL_CHANGED_ATTR", false);
#endif