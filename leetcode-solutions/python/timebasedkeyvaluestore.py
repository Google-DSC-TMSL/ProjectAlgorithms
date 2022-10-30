class TimeMap:
def __init__(self):
        self.dict = defaultdict(list)
        
    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dict[key].append((timestamp, value))
def get(self, key: str, timestamp: int) -> str:
        l, r = 0, len(self.dict[key])-1
        
        while l <= r:
            mid = (l+r)//2
            if values[mid][0] == timestamp: return values[mid][1]
            elif values[mid][0] < timestamp:
                l = mid+1
            else:
                r = mid-1
                
        return values[r][1] if r >= 0 else ""