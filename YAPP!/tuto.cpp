
#include "stdafx.h"
#include "YAPP!.h"
#include "gamedef.h"


void tuto(Player *player, int *save, char (*map)[WIDTH], TRAP trap[],int * stage, MapBox (*mapbox)[WIDTH], int * reset)
{
	static int first=0;
	static char c_map[HEIGHT][WIDTH]={
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//0
	{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//1
	{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//2
	{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//3
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//4
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//5
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//6
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//7
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//8
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#'},//9
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' '},//10
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#',' '},//11
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//12
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//13
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#'},//14
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},//15
	{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},//16
	{' ','#','#',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#'},//17	
	{' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//18
	{' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//19
	{' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//20
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}//21
	// 0  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31
	};
	static char save_map[HEIGHT][WIDTH];
	clear(930,210,960,270,player,stage,TUTORIAL2);
	savePoint(4,17,5,18,player,stage,reset[0]);
	if(first==0)
		insert_map2(save_map,c_map);
	if(first==0 || reset[0]==RESET)
	{	
		insert_map2(c_map,save_map);
		Box a[3]={{13*BOXSIZE,16*BOXSIZE,16*BOXSIZE,17*BOXSIZE},
			{13*BOXSIZE,15*BOXSIZE,16*BOXSIZE,16*BOXSIZE},
			{30*BOXSIZE,15*BOXSIZE,31*BOXSIZE,17*BOXSIZE}
		};
		TRAP inst[3]={{a[0],1,1,0,16,16,2,0,3,LRTYPE,DIE},
		{a[1],1,1,0,15,16,2,0,1,LRTYPE,MOVE_LIMIT},
		{a[2],2,1,0,29,14,17,0,1,UDTYPE,DIE}}; //{�νĹ���, ������� ���� ����,����, ī��Ʈ(�⺻ 0),x��ǥ, �����ϴ���ǥ,��������ǥ,���ӵ�,�ӵ�}

		trap[0]=inst[0];
		trap[1]=inst[1];
		trap[2]=inst[2];
		first++;
		reset[0]=0;
	}
	insert_map2(map, c_map);
	insert_map1(map, mapbox);
  // TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	trapf(&trap[0],player,map,mapbox,save);
	trapf(&trap[1],player,map,mapbox,save);
	trapf(&trap[2],player,map,mapbox,save);
	FC_Crash(player, map, save, mapbox);
	insert_map2(c_map, map);
	//mapCheck2(player, map, save);
}
void DrawBlockTuto(HDC hdc,HDC backDC,HDC mapDC, TRAP trap[], int *stage, HINSTANCE hInst, char (*map)[WIDTH])
{
	HDC saveDC = CreateCompatibleDC(hdc);
	HBITMAP savebit = LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP11));
	SelectObject(saveDC,savebit);
	switch(stage[0])
			{
				case TUTORIAL1:
					for(int k=0;k<3;k++)
					{
						if(trap[k].count==1)
						{
							for(int i=0;i<trap[k].val;i++)
								for(int j=0;j<trap[k].hor;j++)
								{
									BitBlt(backDC, trap[k].present.left+(i-1)*BOXSIZE, trap[k].present.top+(j-1)*BOXSIZE, BOXSIZE, BOXSIZE, mapDC, 0, 0, SRCCOPY);
								};
						}
					}
					break;
				case TUTORIAL2:
					HDC ButtonDC = CreateCompatibleDC(hdc);
					HDC kupaDC = CreateCompatibleDC(hdc);
					HDC fireDC = CreateCompatibleDC(hdc);

					HBITMAP buttonbit = LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP4));
					HBITMAP kupabit = LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP5));
					HBITMAP firebit = LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP6));

					SelectObject(ButtonDC,buttonbit);
					SelectObject(kupaDC,kupabit);
					SelectObject(fireDC,firebit);

					for(int k=0;k<4;k++)
					{
						if(trap[k].count==1)
						{
							for(int i=0;i<trap[k].val;i++)
								for(int j=0;j<trap[k].hor;j++)
								{
									BitBlt(backDC, trap[k].present.left+(i-1)*BOXSIZE, trap[k].present.top+(j-1)*BOXSIZE, BOXSIZE, BOXSIZE, mapDC, 0, 0, SRCCOPY);
								};
						}
					}
					if(trap[5].count==BOSSUP||trap[5].count==BOSSRAID || trap[5].count== BOSSFIRE || trap[5].count==BEATBOSS)
					{

						if(trap[5].count!=BEATBOSS)
							BitBlt(backDC,4*BOXSIZE,18*BOXSIZE,BOXSIZE,BOXSIZE,ButtonDC,0,0,SRCCOPY);
						if(trap[5].count== BOSSFIRE)
							BitBlt(backDC,17*BOXSIZE,17*BOXSIZE-170,120,170,fireDC,0,0,SRCCOPY);
						BitBlt(backDC,trap[5].present.left,trap[5].present.top,210,290,kupaDC,0,0,SRCCOPY);
					}

					DeleteObject(buttonbit);
					DeleteObject(firebit);
					DeleteObject(kupabit);

					DeleteDC(ButtonDC);
					DeleteDC(fireDC);
					DeleteDC(kupaDC);
					break;
			}
			for(int i=0;i<HEIGHT-1;i++){
				for(int j=0;j<WIDTH-1;j++)
				{
					if(map[i][j]=='#'){
						BitBlt(backDC, (j-1)*BOXSIZE, (i-1)*BOXSIZE, BOXSIZE, BOXSIZE, mapDC, 0, 0, SRCCOPY);
					}
					else if (map[i][j] =='s')
					{
						BitBlt(backDC, (j-1)*BOXSIZE, (i-1)*BOXSIZE, BOXSIZE, BOXSIZE, saveDC, 0, 0, SRCCOPY);
					}
				}
			}
			DeleteObject(savebit);
			DeleteDC(saveDC);
}
void tuto2(Player *player, int *save, char (*map)[WIDTH], TRAP trap[], int * stage, MapBox (*mapbox)[WIDTH],int *reset)
{
	static int first=0;
	static char c_map[HEIGHT][WIDTH]={
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//0
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//1
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//2
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//3
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//4
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//5
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//6
		{' ',' ','s',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//7
		{' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//8
		{'#','#','#','#','#','#','#',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//9
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//10
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//11
		{' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//12
		{' ','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//13
		{' ','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//14
		{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' '},//15
		{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//16
		{' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},//17
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//18
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//19
		{' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},//20
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}//21
		//0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30 31  32
	};
	static char save_map[HEIGHT][WIDTH];
	clear(0,210,30,270,player,stage,TUTORIAL1);
	clear(21*BOXSIZE,21*BOXSIZE,29*BOXSIZE,22*BOXSIZE,player,stage,STAGE1_1);
	savePoint(2,7,3,8,player,stage,reset[0]);
	if(first==0)
		insert_map2(save_map,c_map);
	if(first==0 || reset[0]==RESET)
	{
		insert_map2(c_map, save_map);
		Box a[4]={{5*BOXSIZE,6*BOXSIZE,7*BOXSIZE,8*BOXSIZE},
		{3*BOXSIZE,15*BOXSIZE,6*BOXSIZE,16*BOXSIZE},
		{11*BOXSIZE,17*BOXSIZE,12*BOXSIZE,18*BOXSIZE},
		{14*BOXSIZE,17*BOXSIZE,15*BOXSIZE,18*BOXSIZE}
		};

		TRAP inst[4]={{a[0],2,1,0,5,8,3,0,4,DUTYPE,MOVE_LIMIT},
		{a[1],4,3,0,3,18,21,0,6,UDTYPE,MOVE_LIMIT},
		{a[2],1,1,0,11,18,3,2,3,DUTYPE,MOVE_LIMIT,RE},
		{a[3],1,1,0,14,18,3,2,3,DUTYPE,MOVE_LIMIT,RE}
		}; //{�νĹ���, ������� ���� ����,����, ī��Ʈ(�⺻ 0),x��ǥ, �����ϴ���ǥ,��������ǥ,���ӵ�,�ӵ�}
		for(int i=0;i<4;i++)
			trap[i]=inst[i];
		first++;
		reset[0]=0;
	}
	insert_map2(map, c_map);
	insert_map1(map, mapbox);
	for(int i=0;i<4;i++)
		trapf(&trap[i],player,map,mapbox,save);
	tuto2Set(player,trap,map,mapbox);
	FC_Crash(player, map, save, mapbox); 
	insert_map2(c_map, map);
}
void tuto2Set(Player player[], TRAP trap[], char (*map)[WIDTH], MapBox (*mapbox)[WIDTH])
{
	Box reco={18*BOXSIZE,14*BOXSIZE,20*BOXSIZE,18*BOXSIZE};
	static int count=0;
	if(trap[0].present.top<=3*BOXSIZE +PLAYERSIZE &&player[1].top<3*BOXSIZE )
	{
		player[0].life=0;
		player[1].life=0;
	}
	if(trap[2].present.top<=3*BOXSIZE +PLAYERSIZE &&player[1].top<3*BOXSIZE )
	{
		player[0].life=0;
		player[1].life=0;
	}
	if(trap[3].present.top<=3*BOXSIZE +PLAYERSIZE &&player[1].top<3*BOXSIZE )
	{
		player[0].life=0;
		player[1].life=0;
	}
	if(trap[2].count==0  && player[0].top>18*BOXSIZE && (11*BOXSIZE<=player[0].left && player[0].left<=12*BOXSIZE))
	{
		player[0].life=0;
		player[1].life=0;
	}
	if(trap[3].count==0 && player[0].top>18*BOXSIZE && (14*BOXSIZE<=player[0].left && player[0].left<=15*BOXSIZE))
	{
		player[0].life=0;
		player[1].life=0;
	}
	if(trap[5].count>=BOSSUP || recognizer(reco,player[0]))
	{
		if(count==0){
			trap[5].count=BOSSUP;
		}


		count++;
		if(count%50==0&& count<200)
		{
			Box boxReco={17*BOXSIZE-PLAYERSIZE,(14+count/50)*BOXSIZE,18*BOXSIZE+PLAYERSIZE,(15+count/50)*BOXSIZE};
			map[14+count/50][17]='#';
			mapbox[14+count/50][17].value='#';
			if(recognizer(boxReco,player[0]))
			{
				player[0].life=0;
				player[1].life=0;
			}
		}
		bossRaid(player,map,mapbox,trap);
	}

}
void bossRaid(Player player[], char (*map)[WIDTH], MapBox (*mapbox)[WIDTH],TRAP trap[])
{

	if(trap[5].count==BOSSUP)  // �������������� ���İ� �����
	{
		for(int a=21;a<29;a++)
			for(int b=1;b<4;b++)
			{
				map[b][a]=' ';
				mapbox[b][a].value=' ';
			}
		trap[5].present.left=630;
		trap[5].present.right=630+210;
		trap[5].present.top=-270;
		trap[5].present.bottom=20;
		map[20][5]='#';
		mapbox[20][5].value='#';
		FC_insert(mapbox);
		trap[5].count=BOSSRAID;


	}

	if(trap[5].count==BOSSRAID|| trap[5].count== BOSSFIRE)
	{
		Box button={5*BOXSIZE-PLAYERSIZE,18*BOXSIZE-PLAYERSIZE,6*BOXSIZE+PLAYERSIZE,19*BOXSIZE+PLAYERSIZE};

		if(trap[5].present.bottom<17*BOXSIZE){
			trap[5].present.top+=5;
			trap[5].present.bottom+=5;
		}
		else if (trap[5].present.bottom>=17*BOXSIZE-5)
		{
			trap[5].count=BOSSFIRE;
			Box a={18*BOXSIZE,13*BOXSIZE,27*BOXSIZE,18*BOXSIZE};
			if(recognizer(a,player[0]))
			{
				player[0].life=0;
				player[1].life=0;
			}
		}
		if(recognizer(button,*player))          //��ư�� ���� ��� ���� �����鼭 Ŭ����
		{
			trap[5].count=BEATBOSS;
			map[17][17]=map[16][17]=map[15][17]=' ';
			mapbox[17][17].value=mapbox[16][17].value=mapbox[15][17].value=' ';
		}
	}
	else if(trap[5].count==BEATBOSS)
	{
		for(int a=21;a<29;a++)
			for(int b=18;b<21;b++)
			{
				map[b][a]=' ';
				mapbox[b][a].value=' ';
			}
		FC_insert(mapbox);
		trap[5].present.top+=30;
		trap[5].present.bottom+=30;
	}

}