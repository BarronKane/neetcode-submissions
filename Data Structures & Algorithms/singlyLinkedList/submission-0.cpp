class LinkedList {
public:
    LinkedList() {
    }

    ~LinkedList() {
        if (_head == nullptr) {
            return;
        }

        Node * target = _head;
        Node * next = nullptr;

        do {
            next = target->next;
            delete target;
            target = next;
        } while (next != nullptr);
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    int get(int index) {
        if (_head == nullptr || index < 0) {
            return -1;
        }

        int i = 0;
        Node * target = _head;

        while (i < index) {
            if (target->next == nullptr)
            {
                return -1;
            }

            target = target->next;
            i++;
        }

        return target->data;
    }

    void insertHead(int val) {
        Node * newNode = new Node{val, _head};
        _head = newNode;
    }
    
    void insertTail(int val) {
        if (_head == nullptr) {
            insertHead(val);
            return;
        }

        Node * newNode = new Node{val};

        Node * target = _head;
        while (target->next != nullptr)
        {
            target = target->next;
        }

        target->next = newNode;
    }

    bool remove(int index) {
        if (_head == nullptr || index < 0) {
            return false;
        }

        int i = 0;
        Node * prior = nullptr;
        Node * target = _head;

        while (i < index) {
            if (target->next == nullptr)
            {
                return false;
            }

            prior = target;
            target = target->next;
            i++;
        }

        if (prior == nullptr) {
            // Removing the head.
            _head = target->next;
        } else {
            // Removing any other node.
            prior->next = target->next;
        }        

        delete target;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;

        if (_head == nullptr) {
            return values;
        }

        Node * target = _head;

        do {
            values.push_back(target->data);
            target = target->next;
        } while (target != nullptr);

        return values;
    }

private:

    struct Node {
        int data;
        Node* next = nullptr;
    };

    Node* _head = nullptr;
};
