//708

void Insert(Node *& aNode, int x)
{
if(aNode)
{
aNode = new Node(x);
aNode->next = aNode;
return;
}
Node *p =aNode;
Node *prev = NULL;
do
{
prev =p;
p=p->next;
    if(x<= p->data && x>=prev->data)
    break;
    if((prev->data > p->data) && (x< p->data || x> prev->data))
{
    break;
}
}while(p!= aNode);
Node *newNode = new Node(x);
newNode ->next =p;
prev ->next = newNode;
}
