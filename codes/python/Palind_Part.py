
class Solution:
    def palindromicPartition(self, string):
        # code here
        a=string
        cut = [0 for i in range(len(a))]
        palindrome = [[False for i in range(len(a))] for j in range(len(a))]
        for i in range(len(a)):
            minCut = i
            for j in range(i + 1):
                if (a[i] == a[j] and (i - j < 2 or palindrome[j + 1][i - 1])):      
                    palindrome[j][i] = True
                    minCut = min(minCut,0 if  j == 0 else (cut[j - 1] + 1))
            cut[i] = minCut;  
        return cut[len(a) - 1]

# Payel - AIML TMSL
if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
