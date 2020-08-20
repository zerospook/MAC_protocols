#include<bits/stdc++.h>
using namespace std; 

void my_sleep(unsigned msec) 
{
    struct timespec req, rem; 
    int err; 
    req.tv_sec = msec / 1000; 
    req.tv_nsec = (msec % 1000) * 1000000; 
    while ((req.tv_sec != 0) || (req.tv_nsec != 0)) 
    {
        if (nanosleep(&req, &rem) == 0)
            break; 
        err = errno; 
        // Interrupted;  continue
        if (err == EINTR) 
        {
            req.tv_sec = rem.tv_sec; 
            req.tv_nsec = rem.tv_nsec; 
        }
        // Unhandleable error (EFAULT (bad pointer), EINVAL (bad timeval in tv_nsec), or ENOSYS (function not supported))
        break; 
    }
}

void purealoha()
{
  int i, n, k=1, time[10], current_time=1, sent[10], ready[10], in[10], i1=0, count=0, coll=0, s=0; 
  system("cls"); 
  cout<<"THE FRAME TIME IS 2 SECONDS\n\n"; 
  cout<<"Enter number of senders:\t"; 
  cin>>n; 
  for(int i=0;  i<n;  i++)
  {
	 time[i]=(rand()%10+1); 
	 sent[i]=0;   
   ready[i]=0; 
	 cout<<"Sender "<<i+1<<" will send the frame at time "<<time[i]<<"\n"; 
	 my_sleep(2); 
  }
  while(s==0)
  {
  for(i=0;  i<n;  i++)
  {
	 if(current_time==time[i]  &&  sent[i]==0)
	 {
		ready[i]=1; 
	 }
  }
  for(i=0;  i<n;  i++)
  {
	 if(ready[i]==1  &&  count==0)
	 {
		count=1; 
		in[i1]=i; 
		i1++; 
	 }
	 else if(ready[i]==1  &&  count==1)
	 {
		coll=1; 
		in[i1]=i; 
		i1++; 
	 }
  }
  for(i=0;  i<n;  i++)
  {
	 if(time[i]==current_time+1  &&  sent[i]==0  &&  count==1)
	 {
		in[i1]=i; 
		i1++; 
		coll=1; 
	 }
  }
  if(coll == 1)
  {
	 cout<<"Collision Occured at senders\n"; 
  for(i=0; i<=i1-1; i++)
  {
    time[in[i]]=time[in[i]]+k; 
    cout<<"\t"<<in[i]+1; 
    k=k*2; 
  }
  if(i1>1)
	 cout<<"\nThe new time for the collided senders are:\n"; 
  for(i=0; i<=i1-1; i++)
  {
	 cout<<"Sender "<<in[i]+1<<" -> "<<time[in[i]]<<"\n"; 
	 my_sleep(1); 
  }
  }
  if(coll!=1 && count==1)
  {
	 sent[in[i1-1]]=1; 
	 cout<<"Sender "<<in[i1-1]+1<<" has sent the packet\n\n"; 
	 my_sleep(2); 
	 s=1; 
  }
  for(i=0; i<n; i++)
  {
	 if(sent[i]==0)
		s=0; 
  }
  current_time++; 
  for(i=0; i<n; i++)
  {
	 ready[i]=0; 
  }
  count=0; 
  coll=0; 
  i1=0; 
 }
}

void slottedaloha()
{
  int i,n,k=1,time[10],current_time=1,sent[10],ready[10],in[10],i1=0,count=0,coll=0,s=0; 
  system("cls"); 
  cout<<"THE FRAME TIME IS 1 SECOND\n\n"; 
  cout<<"Enter number of senders:\t"; 
  cin>>n; 
  for(int i=0; i<n; i++)
  {
	 time[i]=(rand()%10+1); 
	 sent[i]=0;   ready[i]=0; 
	 cout<<"Sender "<<i+1<<" will send the frame at time "<<time[i]<<"\n"; 
	 my_sleep(2); 
  }
  while(s==0)
  {
  for(i=0; i<n; i++)
  {
	 if(current_time==time[i] && sent[i]==0)
	 {
		ready[i]=1; 
	 }
  }
  for(i=0; i<n; i++)
  {
	 if(ready[i]==1 && count==0)
	 {
		count=1; 
		in[i1]=i; 
		i1++; 
	 }
	 else if(ready[i]==1 && count==1)
	 {
		coll=1; 
		in[i1]=i; 
		i1++; 
	 }
  }
  if(coll==1)
  {
	 cout<<"\nCollision Occured at senders\n"; 
  for(i=0; i<=i1-1; i++)
  {
	 time[in[i]]=time[in[i]]+k; 
	 cout<<"\t"<<in[i]+1; 
	 k=k*2; 
  }
  if(i1>1)
	 cout<<"\nThe new time for the collided senders are:\t"; 
  for(i=0; i<=i1-1; i++)
  {
	 cout<<"\nSender "<<in[i]+1<<" -> "<<time[in[i]]; 
	 my_sleep(1); 
  }
  }
  if(coll!=1 && count==1)
  {
	 sent[in[i1-1]]=1; 
	 cout<<"\nSender "<<in[i1-1]+1<<" has sent the packet"; 
	 my_sleep(2); 
	 s=1; 
  }
  for(i=0; i<n; i++)
  {
	 if(sent[i]==0)
		s=0; 
  }
  current_time++; 
  for(i=0; i<n; i++)
  {
	 ready[i]=0; 
  }
  count=0; 
  coll=0; 
  i1=0; 
  }
}

void csmaca()
{
  int i,n,sent[10],c=-1,ready[10],exp=1,f[10],current_time=1,k=1,s=0,busy=0; 
  float time[10]; 
  system("cls"); 
  cout<<"Enter the senders:\t"; 
  cin>>n; 
  for(int i=0; i<n; i++)
  {
    time[i]=(rand()%10+1); 
    sent[i]=0;  ready[i]=0;   f[i]=0; 
    cout<<"\nSender "<<i+1<<" will send the frame at time "<<time[i]; 
    my_sleep(3); 
  }
  while(s==0)
  {
    for(i=0; i<n; i++)
    {
      if(current_time==time[i] && sent[i]==0 && busy==0 && ready[i]==0)
      {
	ready[i]=1; 
	time[i]=time[i]+0.96; 
	cout<<"\nSender "<<i+1<<" will wait for IFS time"; 
	cout<<"\nSo the time at which it will send the frame is "<<time[i]; 
	my_sleep(2); 
	c=current_time; 
      }
      else if(current_time==time[i] && sent[i]==0 && ready[i]==0)
      {
	time[i]=time[i]+pow(2,exp); 
	exp++; 
	cout<<"\nSince the channel was busy, the transmission time of the sender "<<i+1<<" has been shifted to the time "<<time[i]<<" to avoid collision"; 
	my_sleep(3); 
      }
      else if(current_time>time[i] && sent[i]==0 && f[i]==1)
      {
	cout<<"\nSender "<<i+1<<" has sent the frame at time "<<time[i]; 
	sent[i]=1; 
	busy=1; 
	s=1; 
	my_sleep(2); 
      }
    }
    if(busy==0 && c==current_time-1)
    {
      for(i=0; i<n; i++)
      {
	if(ready[i]==1 && sent[i]==0)
	{
	  int r=pow(2,k)-1; 
	  r=rand()%(r+1); 
	  time[i]=time[i]+r; 
	  cout<<"\n\nThe number of slots for which sender "<<i+1<<" will wait is "<<r<<"\n\n"; 
	  my_sleep(2); 
	  f[i]=1; 
	}
      }
    }
    else if(c==current_time-1)
    {
      time[i]=time[i]+pow(2,exp); 
      exp++; 
      cout<<"\nSince the channel was busy, the transmission time of the sender "<<i+1<<" has been shifted to the time "<<time[i]<<" to avoid collision"; 
      my_sleep(3); 
    }
    for(i=0; i<n; i++)
    {
      if(sent[i]==0)
	s=0; 
    }
    current_time++; 
    busy=0; 
  }
}

void csmacd()
{
  int i,n,time[10],exp=1,size[10],current_time=1,sent[10],ready[10],in[10],i1=0,count=0,coll=0,busy=0,c; 
  system("cls"); 
  cout<<"The frame time is 1 second\n"; 
  cout<<"Enter number of senders:\t"; 
  cin>>n; 
  for(int u=0; u<n; u++){
  cout<<"Enter the number of frames for sender " <<u+1<<"\t"; 
  cin>>size[u]; 
  }
  for(int i=0; i<n; i++)
  {
	 time[i]=(rand()%10+1); 
	 sent[i]=0;   ready[i]=0; 
	 cout<<"Sender "<<i+1<<" will send the frame at time "<<time[i]<<"\n"; 
	 my_sleep(2); 
  }
  while(current_time<=20)
  {
  for(i=0; i<n; i++)
  {
	 if(current_time==time[i] && sent[i]==0 && busy==0)
	 {
		ready[i]=1; 
		busy=1; 
		c=current_time+size[i]; 
		cout<<"\n\nAt time "<<current_time<<" sender "<<i+1<<" is sending the frame for the next "<<size[i]<<" seconds i.e till "<<c; 
		my_sleep(2); 
	 }
	 else if(current_time==time[i])
	 {
		time[i]=time[i]+pow(2,exp); 
		exp++; 
		cout<<"\nSince the channel was busy, the transmission time of the sender "<<i+1<<" has been shifted to the time "<<time[i]<<" to avoid collision"; 
		my_sleep(2); 
	 }
  }
  if(coll!=1 && count==1)
  {
	 sent[in[i1-1]]=1; 
	 cout<<"\nSender "<<in[i1-1]+1<<" has sent the packet"; 
	 my_sleep(2); 
  }
  current_time++; 
  if(c==current_time)
	 busy=0; 
  for(i=0; i<n; i++)
  {
	 ready[i]=0; 
  }
  count=0; 
  coll=0; 
  }
}

int main()
{
  int ch,a; 
  do
  {
  system("cls"); 
  cout<<"1. Pure Aloha\n"; 
  cout<<"2. Slotted Aloha\n"; 
  cout<<"3. CSMA CD\n"; 
  cout<<"4. CSMA CA\n"; 
  cout<<"5. Exit\n"; 
  cout<<"Enter your choice:\t"; 
  cin>>ch; 
  switch(ch)
  {
    case 1: purealoha(); 
    break; 
    case 2: slottedaloha(); 
    break; 
    case 3: csmacd(); 
    break; 
    case 4: csmaca(); 
    break; 
    case 5: exit(0); 
    default: cout<<"Invalid choice"; 
    break; 
  }
  cout<<"\n\nDo you want to continue?? Press 1 for yes:\t"; 
  cin>>a; 
  }while(a==1); 
  
  return 0; 
}