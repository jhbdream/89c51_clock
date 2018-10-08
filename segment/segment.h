
#define SPACE 10
#define NONE  70
typedef struct led
{
	char hour ;
	char min  ;
	char sec  ;
}segment;
extern segment Time;
extern segment WATCH;
extern char display_buf[7];
void clear();
void write_buf( segment * seg);
void display();
void show_num(unsigned char num);
void Dis_Hour( segment * seg);
void Dis_Min( segment * seg);
void Dis_Sec( segment * seg);

