class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class MyLinkedList:

    def __init__(self):
        self.head=None
        self.len=0

    def get(self, index: int) -> int:
        if index<0 or index>self.len:
            return -1
        count=0
        current=self.head
        while current!=None:
            if count==index:
                return current.data
            count+=1
            current=current.next
        return -1
        

    def addAtHead(self, val: int) -> None:
        nod=node(val)
        if self.head==None:
            self.head=nod
            self.len+=1
        else:
            nod.next= self.head
            self.head=nod
            self.len+=1

    def addAtTail(self, val: int) -> None:
        put=node(val)
        if self.head==None:
            self.head=put
            self.len+=1
        else:
            current=self.head
            while current.next!=None:
                current=current.next
            current.next=put
            self.len+=1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.len:
            return
        if index == 0:
            self.addAtHead(val)
        else:
            new = node(val)
            current = self.head
            for i in range(index - 1):
                current = current.next
            new.next = current.next
            current.next = new
            self.len += 1


    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.len:
            return

        if index == 0:
            self.head = self.head.next
        else:
            current = self.head
            for i in range(index - 1):
                current = current.next
            current.next = current.next.next
        self.len -= 1

        
            


        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)