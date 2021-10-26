class HashTable
{
public:
   . . .
   int count(string x) const;
private:
   vector<Node*> buckets;
   int current_size;
};
int HashTable::count(string x) const
{
   int h = hash_code(x); 1
   h = h % buckets.size(); 2
   Node* current = buckets[h]; 3
   while (current != nullptr)
   {
      bool found = current->data == x; 46
      if (found)
      {
         return 1;
      }
      current = current->next; 5
   }
   return 0;
}
