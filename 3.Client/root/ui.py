# Find in class TitleBar(Window):
	def SetCloseEvent(self, event):
		self.btnClose.SetEvent(event)

# Add
	# if app.BL_CHANGED_ATTR or app.ENABLE_DETAILS_UI:
	if app.BL_CHANGED_ATTR:
		def CloseButtonHide(self) :
			if localeInfo.IsARABIC():
				self.imgLeft.LoadImage("d:/ymir work/ui/pattern/titlebar_right_02.tga")
				self.imgLeft.LeftRightReverse()
				self.btnClose.Hide()
			else:
				self.imgRight.LoadImage("d:/ymir work/ui/pattern/titlebar_right_02.tga")
				self.btnClose.Hide()