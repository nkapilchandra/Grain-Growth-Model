struct Node{
  int q;
  float Val;
  struct Node* next;
};
struct Track{
  int i;
  int j;
  int grain;
  float val;
  struct Track *link;
};
struct Pivot{
  int x;
  int y;
  int q;
  struct Pivot* next;
};
float dist(int i1,int j1,int i2,int j2){
  return ((i1-i2)*(i1-i2)+(j1-j2)*(j1-j2));
}

float crawl(struct Node* head,int check){
  struct Node* tempo;
  tempo = head;
  if(head == NULL)
    return 0.0;
  if(tempo->q == check)
    return tempo->Val;
  while(tempo->q != check){
    tempo = tempo->next;
    if(tempo == NULL){
      return 0.0;
    }
    if(tempo->q == check){
      return tempo->Val;
    }
  }
}
int colorize(struct Node* head){
  struct Node* temp;
  float max_value;
  int max_q;
  temp = head;
  if(head == NULL){
    return 0;
  }
  max_value = temp->Val;
  max_q = temp->q;
  while(temp != NULL){
    if(max_value < temp->Val){
      max_value = temp->Val;
      max_q = temp->q;
    }
    temp = temp->next;
  }
  return max_q;
}
struct Node* attach(struct Node* head,int grain,float value){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->q = grain;
  temp->Val = value;
  temp->next = head;
  head = temp;
  return head;
}
struct Pivot* stick(struct Pivot* head,int index1,int index2,int grain){
  struct Pivot* temp = (struct Pivot*)malloc(sizeof(struct Pivot));
  temp->x = index1;
  temp->y = index2;
  temp->q = grain;
  temp->next = head;
  head = temp;
  return head;
}
struct Track* append(struct Track* head,int index1,int index2,int Grain,float value){
  struct Track* temp3 = (struct Track*)malloc(sizeof(struct Track));
  temp3->i = index1;
  temp3->j = index2;
  temp3->grain = Grain;
  temp3->val = value;
  temp3->link = head;
  head = temp3;
  return head;
}

struct Node* delete(struct Node* head,int n){
  struct Node* temp = head;
  if(n==1){
    head = temp->next;
    free(temp);
    return head;
  }
  for(int i=0;i<n-2;i++){
    temp = temp -> next;
  }
  struct Node* temp2 = temp -> next;
  temp -> next = temp2 -> next;
  free(temp2);
  return head;
}
struct Track* del(struct Track* head,int num){
  struct Track* temp1 = head;
  if(num ==1){
    head = head->link;
    free(temp1);
    return head;
  }
  for(int i=0;i<num-2;i++){
    temp1 = temp1->link;
  }
  struct Track* temp2 = temp1->link;
  temp1->link = temp2->link;
  free(temp2);
  return head;
}
struct Pivot* pop(struct Pivot* head,int num){
  struct Pivot* temp1 = head;
  if(num==1){
    head= head->next;
    free(temp1);
    return head;
  }
  for(int i=0;i<num-2;i++){
    temp1 = temp1->next;
  }
  struct Pivot* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
  return head;
}
struct Node* change(struct Node* head,int check,float new){
  struct Node* tem;
  tem = head;
  if(tem->q == check){
    tem->Val = new;
    return head;
  }
  while(tem->q != check){
    tem = tem->next;
    if(tem == NULL){
      return head;
      break;
    }
    if(tem->q == check){
      tem->Val = new;
      return head;
      break;
    }
  }
}

struct Node* clear(struct Node* head){
  while(head != NULL){
    head = delete(head,1);
  }
  return head;
}
struct Track* flush(struct Track* head){
  while(head != NULL){
    head = del(head,1);
  }
  return head;
}
struct Pivot* erase(struct Pivot* head){
  while(head != NULL){
    head = pop(head,1);
  }
  return head;
}
void Print(struct Node* head){
  struct Node* here = head;
  while(here != NULL){
    printf("%f grain=%d ",here->Val,here->q);
    here = here->next;
  }
  printf("\n");
}

void show(struct Track* head){
  struct Track* there = head;
  while(there != NULL){
    printf("%f grain=%d ",there->val,there->grain);
    there = there->link;
  }
  printf("\n");
}
void output(struct Pivot* head){
  struct Pivot* a = head;
  while(a != NULL){
    printf("i=%d j=%d q=%d \n",a->x,a->y,a->q);
    a = a->next;
  }
  printf("\n");
}
