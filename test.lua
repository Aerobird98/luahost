--local test = require("test")

print("guest says: trying to call test function...")
if test then
 test.testf()
 print("guest says: thanks!")
else
 print("quest says: so??")
end

