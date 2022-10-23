
class Solution:
   
    def findOrder(self, words, N, K) -> str:
        indegree = {char:set() for word in words for char in word}
        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i+1]
            minLeng = min(len(word1), len(word2))
            if len(word1) > len(word2) and word1[:minLeng] == word2[:minLeng]:
                return ""
            for j in range(minLeng):
                if word1[j] != word2[j]:
                    indegree[word1[j]].add(word2[j])
                    break
        visited = {}
        res = []
        def dfs(c):
            if c in visited:
                return visited[c]
            visited[c] = True
            for neighbor in indegree[c]:
                if dfs(neighbor):
                    return True
            visited[c] = False
            res.append(c)
        for c in indegree:
            if dfs(c):
                return ""
        res.reverse()
        return "".join(res)

# Payel - AIML TMSL

class sort_by_order:
    def __init__(self,s):
        self.priority = {}
        for i in range(len(s)):
            self.priority[s[i]] = i
    
    def transform(self,word):
        new_word = ''
        for c in word:
            new_word += chr( ord('a') + self.priority[c] )
        return new_word
    
    def sort_this_list(self,lst):
        lst.sort(key = self.transform)

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        line=input().strip().split()
        n=int(line[0])
        k=int(line[1])
        
        alien_dict = [x for x in input().strip().split()]
        duplicate_dict = alien_dict.copy()
        ob=Solution()
        order = ob.findOrder(alien_dict,n,k)
        s = ""
        for i in range(k):
            s += chr(97+i)
        l = list(order)
        l.sort()
        l = "".join(l)
        if s != l:
            print(0)
        else:
            x = sort_by_order(order)
            x.sort_this_list(duplicate_dict)
            
            if duplicate_dict == alien_dict:
                print(1)
            else:
                print(0)

