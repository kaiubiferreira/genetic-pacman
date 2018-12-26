struct tQueueNode
{
    int value;
    int distance;
    struct tQueueNode * next;
};

class Queue
{
    private:    struct tQueueNode * root;
                struct tQueueNode * last;
                int quantity;

    public:
            Queue()
            {
                this->quantity = 0;
                this->root = this->last = NULL;
            }

            ~Queue()
            {
                if(root != NULL)
                    delete root;
                if(last != NULL)
                    delete last;
            }

            struct tQueueNode * createNode(int value, int distance)
            {
                struct tQueueNode * newNode = (struct tQueueNode *) malloc(sizeof(struct tQueueNode));
                newNode->value = value;
                newNode->distance = distance;
                newNode->next = NULL;

                return newNode;
            }

            void enqueue(int value, int distance)
            {
                struct tQueueNode * newNode = createNode(value, distance);

                if(root == NULL)
                {
                    root = last = newNode;
                }
                else
                {
                    last->next = newNode;
                    this->last = newNode;
                }
                quantity++;
            }

            struct tQueueNode * dequeue()
            {
                struct tQueueNode * node;

                if(root == NULL)
                {
                    return NULL;
                }
                else
                {
                    node = this->root;
                    this->root = root->next;
                    this->quantity--;
                }

                return node;
            }

            void printQueue()
            {
                struct tQueueNode * node = root;
                while(node != NULL)
                {
                    cout << node->value << endl;
                    node = node->next;
                }
            }

            int getQuantity()
            {
                return this->quantity;
            }
};
