# Python3 code to demonstrate
# Interleaving two strings
# using join() + zip()
  
# initializing strings 
test_string1 = 'mathematics'
test_string2 = 'computerfreak'
  
# printing original strings  
print("The original string 1 : " + test_string1)
print("The original string 2 : " + test_string2)
  
# using join() + zip()
# Interleaving two strings
res = "".join(i + j for i, j in zip(test_string1, test_string2))
      
# print result
print("The Interleaved string : " + str(res))
