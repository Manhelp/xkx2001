//Cracked by Roath
// pan83.c ��ʮ����
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "��ʮ����");
	set("long", @LONG
��ʮ���̣���·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·���Ǳ��������
��ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ���������������µ�ϴ��ء�
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"pan84",
		"southup" : __DIR__"pan82",
		"east" : __DIR__"lenshan3",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 4);
	setup();
//	replace_program(ROOM);

}
int valid_leave(object me, string dir)
{
                int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southup" && current_jingli >15)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(10));
                write("�����ϰ�ʮ���̣���Щ���ˡ�\n");
        }

        else if (dir == "southup" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}
