#include <scws/scws.h>
#include <stdlib.h>

main()
{
    scws_t s;
    scws_res_t res, cur;
    char *test = "【做空】test";
    char *text = "【做空机构香橼这样搞垮中国公司】香橼只有一名正式员工，就是莱福特本人。他不懂中文，至少近10年未踏足中国，他雇佣翻译，对材料进行分析，找自己的进攻目标，先后狙击20多家中国概念股公司，7家已经退市。由@李开复 牵头，众多投资者与企业家，联名抗议香橼等做空机构http://t.cn/zWdje63";

    printf("test + 3: %s\n", test+3);

    if (!(s=scws_new())) {
        printf("init scws failed!\n");
        exit(-1);
    }

    scws_set_charset(s,"utf8");
    scws_set_dict(s,"/usr/local/Cellar/scws/etc/dict.utf8.xdb",SCWS_XDICT_XDB);
    scws_set_rule(s,"/usr/local/Cellar/scws/etc/rules.utf8.init");

    scws_send_text(s,text,strlen(text));
    while(res=cur=scws_get_result(s)){
        while(cur!=NULL){
            printf("text off: %d\n", cur->off);
            printf("Word: %.*s\n",cur->len,text+cur->off);
            cur=cur->next;
        }
        scws_free_result(res);
    }

    scws_free(s);
}
