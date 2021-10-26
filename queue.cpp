class LinkedListQueue
{
public:
   LinkedListQueue();
   void push(string element);
   string front() const;
   void pop();
private:
   Node* first;
   Node* last;
};
LinkedListQueue::LinkedListQueue() { first = last = nullptr; }

void LinkedListQueue::push(string element)
{
   Node* new_node = new Node; 12
   new_node->data = element; 3
   new_node->next = nullptr; 4
   if (last == nullptr) { first = new_node; }
   else { last->next = new_node; } 5
   last = new_node; 6
} 7
string LinkedListQueue::front() const
{
   return first->data; 8
}
void LinkedListQueue::pop()
{
   Node* removed = first; 910
   first = first->next;  11
   delete removed; 12
   if (first == nullptr) { last = nullptr; }
}  13

int main()
{
   LinkedListQueue queue;
   ...
   queue.push("X");
   string front = queue.front();
   queue.pop();
   ...
}
