#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll()
{
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s)
{
  Student *copy = new Student(s);
  Node *insert_node = new Node{copy, NULL};
  if (head == NULL) // this case, there is no Node
  {
    head = insert_node;
    tail = insert_node;
  }
  else // there is at least one Node for this case
  {
    Node *progress_node = head;
    while (progress_node->next != NULL)
    {
      progress_node = progress_node->next;
    }
    progress_node->next = insert_node;
    tail = insert_node;
  }
}

std::string StudentRoll::toString() const
{
  std::string result = "";
  if (head == NULL)
  {
    return "[]";
  }
  Node *progress_node = head;
  result += "[";
  while (true)
  {
    result += progress_node->s->toString();
    if (progress_node->next == NULL)
    {
      break;
    }
    else
    {
      result += ",";
    }
    progress_node = progress_node->next;
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig)
{
  if (!orig.head) // this case, the copied StudentRoll has zero student
  {
    head = tail = NULL;
  }
  else // this case, the copied StudentRoll has at least one student
  {
    Student *first_student = new Student(*(orig.head->s));
    head = new Node{first_student, NULL};
    Node *progress_node = head; // we will keep add the Nodes on this progress_node
    Node *copy_node = orig.head->next;
    if (!copy_node)
    { // if there's only one node, then head and tail should be the same
      tail = head;
    }
    while (copy_node) // while there is a node to be copied.
    {
      Student *insert_student = new Student(*(copy_node->s));
      Node *insert_node = new Node{insert_student, NULL};
      progress_node->next = insert_node; // set the previous node's next
      copy_node = copy_node->next;
      progress_node = insert_node;
      if (!copy_node)
      {
        tail = insert_node;
      }
    }
  }
}

StudentRoll::~StudentRoll()
{
  Node *progress_node = head;
  while (progress_node)
  {
    Node *next_node = progress_node->next;
    delete progress_node->s;
    delete progress_node;
    progress_node = next_node;
  }
  head = tail = NULL;
}

StudentRoll &StudentRoll::operator=(const StudentRoll &right)
{
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this)
    return (*this);

  // TODO... Here is where there is code missing that you need to
  // fill in...
  Node *delete_node = head;
  while (delete_node)
  {
    Node *next_node = delete_node->next;
    delete delete_node->s;
    delete delete_node;
    delete_node = next_node;
  }
  head = tail = NULL;  
  if (right.head)// this case, the copied StudentRoll has at least one student
  {
    Student *first_student = new Student(*(right.head->s));
    head = new Node{first_student, NULL};
    Node *progress_node = head; // we will keep add the Nodes on this progress_node
    Node *copy_node = right.head->next;
    if (!copy_node)
    { // if there's only one node, then head and tail should be the same
      tail = head;
    }
    while (copy_node) // while there is a node to be copied.
    {
      Student *insert_student = new Student(*(copy_node->s));
      Node *insert_node = new Node{insert_student, NULL};
      progress_node->next = insert_node; // set the previous node's next
      copy_node = copy_node->next;
      progress_node = insert_node;
      if (!copy_node)
      {
        tail = insert_node;
      }
    }
  }
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);
}
