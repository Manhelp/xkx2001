//Cracked by Roath
// Room: /d/beijing/west/fuyoujie2.c

inherit ROOM;

void create()
{
	set("short", "���ҽ�");
	set("long", @LONG
����һ��Ƨ������ʯ��֣�·��ֻ���������伸�����ˣ��뾩��
������ֵ����־���������ԶԶ�����������������������������Ŵ�
���ϵ�����������ʯ��·����һֱ�����ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fuchengmenjie",
  "south" : __DIR__"fuyoujie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}