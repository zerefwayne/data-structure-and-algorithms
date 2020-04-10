```py
def generateIPs(A, idx, curr_ip, ips):
    
    n = len(A)
    
    #If we have four numbers in the array, we have the base condition
    if len(curr_ip) == 4:
        # When idx is n, this means we are at the end of string
        # This means the IP is valid
        if idx == n:
            ips.append('.'.join(curr_ip))
        # If we haven't reached the end, it is invalid
        else:
            return
        
    # We run iterate over idx, idx+1, idx+2
    for i in range(idx, min(n, idx+3)):
        
        # Substring starting at idx of length 1, 2, 3
        num = int(A[idx:i+1])

        if num < 256:
            
            # Normal backtracking code when number is valid
            
            curr_ip.append(A[idx:i+1])
            generateIPs(A, i+1, curr_ip, ips)
            curr_ip.pop()
        
        # If the number was 0, this means we cannot add more in this number
        if num == 0:
            break

class Solution:
	# @param A : string
	# @return a list of strings
	def restoreIpAddresses(self, A):
	    
	    # Stores all IP Addresses
	    ips = []
	    # Denotes the current IP
	    curr_ip = []
	    
	    #Backtracking function is called
	    generateIPs(A, 0, curr_ip, ips)
	    
	    return ips
```