//Cracked by Roath
// nanyanfeng.c ���ҷ� 
// by Fang 8/19/96
// modified by Ryu, 6/13/97;

inherit ROOM;

void create()
{
	set("short", "���ҷ�");
	set("long", @LONG
�������䵱��ʮ����֮��������죬ľʯ���棬�ͱ�����������
֮������һ���������Ԩ�����̺ƴ󡣹�ǰ��һʯ�������ͱ��Ϻ����
LONG
	);
        set("outdoors", "wudang");

	set("objects", ([
		"/kungfu/class/wudang/mo" : 1,
	]));
	set("exits", ([
		"eastdown" : __DIR__"langmei",
		"southdown" : __DIR__"shizhu",
                "west" : __DIR__"sheshenya",
	]));
	set("cost", 3);
	setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "�䵱��") && dir == "southdown"
    && objectp(present("mo shenggu", environment(me))) )
           return notify_fail("Ī������ס��˵���˴��˱��ɽ��أ���ֹ����\n");

    return ::valid_leave(me, dir);
}
