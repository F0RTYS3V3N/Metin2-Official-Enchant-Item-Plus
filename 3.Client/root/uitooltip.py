# Find
	def __GetAffectString(self, affectType, affectValue):
        ...

# Add
	if app.BL_CHANGED_ATTR:
		def GetAffectString(self, affectType, affectValue):
			if 0 == affectType:
				return None

			if 0 == affectValue:
				return None
			
			try:
				# if app.ENABLE_COSTUME_ATTR_RENEWAL_SECOND:
				# 	if affectValue < 0 and affectType in self.AFFECT_MINUS_DICT:
				# 		return self.AFFECT_MINUS_DICT[affectType](affectValue)
				
				return self.AFFECT_DICT[affectType](affectValue)
			except TypeError:
				return "UNKNOWN_VALUE[%s] %s" % (affectType, affectValue)
			except KeyError:
				return "UNKNOWN_TYPE[%s] %s" % (affectType, affectValue)