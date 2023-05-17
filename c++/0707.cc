class MyLinkedList {
public:
    struct ListNode {
        int val;
        union {
            ListNode *next;
            ListNode *head;
        };
        union {
            ListNode *prev;
            ListNode *tail;
        };
        ListNode(int val):val(val), next(nullptr), prev(nullptr) {};
    };

    MyLinkedList() {
        _size = 0;
        _listHead = new ListNode(0);
        _listHead->next = _listHead;
        _listHead->prev = _listHead;
    }
    
    int get(int index) {
        if (index >= _size) {
            return -1;
        }
        if (index < _size/2) {
            ListNode *cur = _listHead->next;
            int i=0;
            while(i != index) {
                cur = cur->next;
                i++;
            }
            return cur->val;
        } else {
            ListNode *cur = _listHead->tail;
            index = _size-index-1;
            int i=0;
            while(i != index) {
                cur = cur->tail;
                i++;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        ListNode *tmp = _listHead->head;
        ListNode *node = new ListNode(val);
        _listHead->head = node;
        node->prev = _listHead;
        node->next = tmp;
        tmp->prev = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode *tmp = _listHead->tail;
        ListNode *node = new ListNode(val);
        _listHead->tail = node;
        node->prev = tmp;
        node->next = _listHead;
        tmp->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
        } else if (index == _size) {
            addAtTail(val);
        } else {
            ListNode *cur_prev;
            ListNode *cur;
            ListNode *node = new ListNode(val);
            if (index < _size/2) {
                cur = _listHead->next;
                int i=0;
                while(i != index) {
                    cur = cur->next;
                    i++;
                }
            } else {
                cur = _listHead->tail;
                index = _size-index-1;
                int i=0;
                while(i != index) {
                    cur = cur->tail;
                    i++;
                }
            }
            cur_prev = cur->prev;
            cur_prev->next = node;
            node->prev = cur_prev;
            node->next = cur;
            cur->prev = node;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        ListNode *cur_prev;
        ListNode *cur;
        if (index < _size/2) {
            cur = _listHead->next;
            int i=0;
            while(i != index) {
                cur = cur->next;
                i++;
            }
        } else {
            cur = _listHead->tail;
            index = _size-index-1;
            int i=0;
            while(i != index) {
                cur = cur->tail;
                i++;
            }
        }
        cur_prev = cur->prev;
        cur_prev->next = cur->next;
        cur->next->prev = cur_prev;
        _size--;
        delete cur;
    }
private:
    int _size;
    ListNode *_listHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList list;

    list.addAtHead(7);
    list.addAtHead(2);
    list.addAtHead(1);
    list.addAtIndex(3,0);
    list.deleteAtIndex(2);
    list.deleteAtIndex(1);
    list.deleteAtIndex(0);
    list.addAtHead(6);
    list.addAtTail(4);
    list.get(4);
    list.addAtHead(4);
    list.addAtIndex(5,0);
    list.addAtHead(6);
    return 0;
}

/*
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],

[7],addAtHead
[2],addAtHead
[1],addAtHead
[3,0],addAtIndex
[2],deleteAtIndex
[6],addAtHead
[4],addAtTail
[4],get
[4],addAtHead
[5,0],addAtIndex
[6]]addAtHead
*/