var scws = require('./build/Release/node_scws');

scws = new scws.Scws('/usr/local/Cellar/scws/etc/dict.utf8.xdb');
//scws.init('/usr/local/Cellar/scws/etc/dict.utf8.xdb');
//scws = new scws.Scws();

var text = "【做空机构香橼这样搞垮中国公司】香橼只有一名正式员工，就是莱福特本人。他不懂中文，至少近10年未踏足中国，他雇佣翻译，对材料进行分析，找自己的进攻目标，先后狙击20多家中国概念股公司，7家已经退市。由@李开复 牵头，众多投资者与企业家，联名抗议香橼等做空机构http://t.cn/zWdje63";
//var text = [];

scws.segment(text,function(error, results){
    if (error) {
        console.log('error: ', error);
    } else {
        console.log('segment result: ', results);
    }
});

//console.log('top words: ', tops);
