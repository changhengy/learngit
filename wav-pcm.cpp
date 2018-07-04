#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<alsa/asoundlib.h>
#include <unistd.h>
using namespace std;

		int main ()
		{	
			size_t result;
			char  *buf;
			FILE *fp1=fopen("awake.wav","rb");
			FILE *fp2=fopen("awake.pcm","wb");
			fseek(fp1,0,SEEK_END);
			long filesize;
			filesize=ftell(fp1);
				if(fp1==NULL||fp2==NULL)
			{	
					cout<<"file open filed!!"<<endl;
					return 0;
			}
			rewind(fp1);
			fseek(fp1,44,SEEK_SET);
			buf=(char *)malloc(sizeof(char)*filesize);
				if(buf==NULL)
			{
					printf ("memory  error");
					return 0;
			}	
			result =fread(buf,1,(filesize-44),fp1);
				if(result!=filesize-44)
			{
				cout<<"reing error!!"<<endl;
				return 0;
			}		
			fwrite(buf,1,(filesize-44),fp2);
		//	memcpy(fp2,fp1,(filesize-44));
		//	fgets(buf,filesize,fp1);
		//	fputs(buf,fp2);
			fclose(fp1);
			fclose(fp2);
			free (buf);
			return 0 ;

		}

