# Add
if app.BL_CHANGED_ATTR :
	import uiSelectAttr

# Find
		self.listGMName = {}

# Add
		if app.BL_CHANGED_ATTR :
			self.wndSelectAttr = None

# Find
		self.wndMall = wndMall

# Add
		if app.BL_CHANGED_ATTR:
			self.wndSelectAttr = uiSelectAttr.SelectAttrWindow()

# Find
		self.wndGuild.SetSkillToolTip(self.tooltipSkill)

# Add
		if app.BL_CHANGED_ATTR :
			self.wndSelectAttr.SetInven(self.wndInventory)

# Find
		if self.wndGameButton:
			self.wndGameButton.Destroy()

# Add
		if app.BL_CHANGED_ATTR :
			self.wndSelectAttr.Destroy()
			del self.wndSelectAttr

# Find
    def CommandCloseSafebox(self):
		self.wndSafebox.CommandCloseSafebox()

# Add
	if app.BL_CHANGED_ATTR :
		def OpenSelectAttrDialog(self, window_type, slotIdx) :
			if self.wndSelectAttr.IsShow() :
				return

			if self.privateShopBuilder.IsShow() :
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.SELECT_ATTR_NOT_OPEN)
				return

			self.wndSelectAttr.Open(window_type, slotIdx)
			self.wndSelectAttr.Show()

# Find
		if self.wndExpandedTaskBar:
			self.wndExpandedTaskBar.Hide()

# Add
		if app.BL_CHANGED_ATTR :
			if self.wndSelectAttr:
				self.wndSelectAttr.Hide()

# Find
	def OpenPrivateShopInputNameDialog(self):
    
# Add before: inputDialog = uiCommon.InputDialog()
		if app.BL_CHANGED_ATTR :
			if self.wndSelectAttr.IsShow() :
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.SELECT_ATTR_NOTICE)
				return

# Find
		if not len(self.inputDialog.GetText()):
			return True

# Add
		if app.BL_CHANGED_ATTR :
			if self.wndSelectAttr.IsShow() :
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.SELECT_ATTR_NOTICE)
				return