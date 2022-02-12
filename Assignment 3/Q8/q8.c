#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define precision 1e-4

int isequal(float a,float b)
{
 return fabs(a-b)<=precision;
}

struct point
{
 float x;
 float y;
 struct point* next;
};  //this linked list represents the polynomial

typedef struct point point;

point* create_point(float x,float y)
{
 point* p = (point*)malloc(sizeof(point));

 p->x=x;
 p->y=y;
 p->next=NULL;
 return p;
}

void insert_front(point** phead,point* target)
{
 target->next = *phead;
 *phead = target;
 return;
}

float distance(point* a, point* b)
{
 return sqrt((b->x-a->x)*(b->x-a->x)+(b->y-a->y)*(b->y-a->y));//return euclidean distance
}

float get_area(point* p, point* p1, point*p2)//area of triangle formed by 3 points
{
 float s1 = distance(p1,p);
 float s2 = distance(p1,p2);
 float s3 = distance(p2,p);
 float semi = (s1+s2+s3)/2;
 float area = sqrt(semi*(semi-s1)*(semi-s2)*(semi-s3));
 return area;
}

float get_poly_area(point* p,point* poly,int* flag)
{
 point* prev = poly;
 point* curr = poly->next;
 float ret = 0;
 while(curr!=NULL)
 {
  ret+=get_area(p,prev,curr);
  if(isequal(get_area(p,prev,curr),0))//if 0 the point lies on edge
    *flag=1;
  prev = curr;
  curr = curr->next;
 }
 ret+=get_area(p,prev,poly);//last edge done separately as not circular list
 if(isequal(get_area(p,prev,poly),0))
    *flag=1;
 return ret;
}

int main()
{
 point* poly1=NULL;
 point* poly2=NULL;
 printf("Enter number of points\n");
 int n;scanf("%d",&n);
 point* dummy_point1 = create_point(0,0);
 point* dummy_point2 = create_point(0,0);
 int flag1=0;int flag2=0;

 printf("Enter points of first polygon in clockwise order\n");
 for(int i=0;i<n;i++)
 {
  float x,y;
  scanf("%f%f",&x,&y);
  dummy_point1->x += x;
  dummy_point1->y += y;
  insert_front(&poly1,create_point(x,y));
 }

 dummy_point1->x/=n;
 dummy_point1->y/=n;
 float area1 = get_poly_area(dummy_point1,poly1,&flag1);

 printf("Enter points of second polygon in clockwise order\n");
 for(int i=0;i<n;i++)
 {
  float x,y;
  scanf("%f%f",&x,&y);
  insert_front(&poly2,create_point(x,y));
  dummy_point2->x+=x;
  dummy_point2->y+=y;
 }

 dummy_point2->x/=n;
 dummy_point2->y/=n;
 float area2 = get_poly_area(dummy_point2,poly2,&flag2);

 int count1=0;
 flag1=0;
 int count2 = 0;
 flag2 = 0;

 point* temp1 = poly1;
 point* temp2 = poly2;

 for(int i=0;i<n;i++)
 {
  float val = get_poly_area(temp2,poly1,&flag1);
  if(!isequal(val,area1))
    count1++; //number of points lying outside the polygon for first polygon
  temp2=temp2->next;
 }

 for(int i=0;i<n;i++)
 {
  float val = get_poly_area(temp1,poly2,&flag2);
  if(!isequal(val,area2))
    count2++; //number of points lying outside the polygon for second polygon
  temp1=temp1->next;
 }

 if(count1==n&&count2==n)//all points
    printf("Not Intersecting\n");
 else if(count1==0&&flag1==1&&count2==n)//touching from inside
    printf("Touching\n");
 else if(count2==0&&flag2==1&&count1==n)//touching from inside
    printf("Touching\n");
 else if((count1==n&&count2==0)||(count1==0&&count2==n))//one completely inside another
    printf("Not intersecting\n");
 else
    printf("Intersecting\n");

}
