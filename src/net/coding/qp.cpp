#include "qp.hpp"

namespace  {

/*
 * Convert a QP hex value to the corresponding string
 * ie: =C3=A9 => é
 * Hex values are always 3 char long (=XX).
 */
string
from_hex_string(const string& s)
{
    string res;
    stringstream ss;
    unsigned int x, n;

    string h = s.substr(1, 2);
    ss << hex << setfill('0') << setw(2) << h;
    ss >> x;
    n = static_cast<int>(x);
    res += n;
    ss.clear();

    return res;
}

} /* namespace  */

string
qp::decode(const string& s)
{
    string res;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            res += from_hex_string(s.substr(i, 3));
            i += 2;
        }
        else {
            res += s[i];
        }
    }

    return res;
}

string
qp::encode(string s)
{
    return s;
}

#ifdef QP_DEBUG

#include <vector>

int
main()
{
    vector<string> qp_subjects = {
        "Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver",
        "FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration",
        "Re:_P=C3=A9pite",
        "Confirmation_pour_votre_voyage_=?UTF-8?Q?PARIS_-_RENNES,_aller_le_22_ao=C3=BBt",
        "Pr=C3=AAt(e)_pour_votre_covoiturage_vers_Pau_=3F",
        "Une_autre_r=C3=A9colte_",
        "Re:_Une_autre_r=C3=A9colte",
        "Confirmation_de_votre_r=C3=A9servation",
        "Re:_Kiffe-moi_=C3=A7a",
        "Re:_Rentr=C3=A9e",
        "Re:_Rentr=C3=A9e",
        "Re:_Non,_mais_l=C3=A0,_c'est_chaud",
        "Re:_Ann=C3=A9e_2015-2016",
        "QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
        "Re=3A_Exercices_Alg=E8bre_de_Boole?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "l=27id=E9e?= =?iso-8859-1?Q?_?=\r\n=?iso-8859-1?Q?int=E9ressante?=\r\n",
        "tutor=E9?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_du_C?=\r\n=?ISO-8859-15?Q?entre_Chine_(Octobre/Novembre,_n=B0_5)?=\r\n",
        "Re:_Devoir_1=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_6)?=\r\n",
        "Re:_Devoir_2=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Novembre,_n=B0_7?=\r\n",
        "s=E9minaire_mardi_25_nov=2E?=\r\n",
    };

    for (unsigned int i = 0; i < qp_subjects.size(); ++i) {
        cout << "decoded  : " << qp::decode(qp_subjects[i], true) << endl;
    }

    cout << from_hex_string("=C3=A9") << endl;

    return 0;
}

#endif
