//Cracked by Roath
// Room: didao_e.c �ص���
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ո��ڳɵĵص������������������졣
LONG
	);
	set("exits", ([
		"west": __DIR__"didao1",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","east");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("east");
	if (num >= 1)
		set("exits/east",__DIR__"didao_e_1");
	else
		delete("exits/east");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}