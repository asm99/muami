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
qp::from_qp(const string& s)
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
qp::to_qp(string s)
{
    return s;
}

#ifdef QP_DEBUG

#include <vector>

int
main()
{
    vector<string> qp_subjects = {
        "=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement",
        "Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver",
        "FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration",
        "Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique",
        "Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique",
        "Marc_:_Fitnessboutique_souhaite_conna=C3=AEtre_votre_avis",
        "Re:_P=C3=A9pite",
        "Confirmation_pour_votre_voyage_=?UTF-8?Q?PARIS_-_RENNES,_aller_le_22_ao=C3=BBt",
        "Fwd=3A_Michel_Boujenah_furax_d=27=C3=AAtre_=C2=ABle_juif=2Dtunisie=?UTF-8?Q?n_de_service=C2=BB",
        "Pr=C3=AAt(e)_pour_votre_covoiturage_vers_Pau_=3F",
        "Une_autre_r=C3=A9colte_",
        "Re:_Une_autre_r=C3=A9colte",
        "Confirmation_pour_votre_voyage_=?UTF-8?Q?RENNES_-_PARIS,_aller_le_16_ao=C3=BBt",
        "Confirmation_de_votre_r=C3=A9servation",
        "Re:_Kiffe-moi_=C3=A7a",
        "Votre=20dernier=20contact=20avec=20AIR=20FRANCE",
        "Confirmation_pour_votre_voyage_P=?UTF-8?Q?ARIS_-_LORIENT,_aller_le_23_ao=C3=BBt",
        "Etats-Unis:_Elle_porte_plainte_contre_une_clinique_apr=?utf-8?Q?=C3=A8s_avoir_accouch=C3=A9_d'un_b=C3=A9b=C3=A9_m=?utf-8?Q?=C3=A9tis",
        "Votre_voyage_=C3=A0_Wuhan_le_23/09/2015_avec_Air_France",
        "Re:_Rentr=C3=A9e",
        "MaribolHD_vous_suit_=C3=A0_pr=C3=A9sent_sur_Twitch",
        "Important_!_Compl=C3=A9tez_votre_dossier_p?= =?UTF-8?Q?our_votre_vol_du_23/09/2015_vers_Wuhan",
        "Re:_Rentr=C3=A9e",
        "Re:_Non,_mais_l=C3=A0,_c'est_chaud",
        "Re:_Ann=C3=A9e_2015-2016",
        "=5Bwww=2Edidactibook=2Ecom=5D_Compte_activ=C3=A9",
        "=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement",
        "[IED_-_EAD_-_ELI000]_Rentr=C3=A9e",
        "[IED_-_EAD_-_ELI000]_Rentr=C3=A9e?=\r\n",
        "QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
        "QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
        "Re=3A_Exercices_Alg=E8bre_de_Boole?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "[IED_-_EAD_-_ISLI1]_EQUIVALENCES=C2=A0:_CETTE_ANNONCE_S'AD?=  =?iso-8859-1?Q?RESSE_UNIQUEMENT_AUX_PRIMO-INSCRITS.?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "Re=3A_Calcul_des_pr=E9dicats?=\r\n",
        "l=27id=E9e?= =?iso-8859-1?Q?_?=\r\n=?iso-8859-1?Q?int=E9ressante?=\r\n",
        "[IED_-_EAD_-_ELI000]_Rappel_:_fin_de_la_premi=C3=A8re_sess?=  =?iso-8859-1?Q?ion?=\r\n",
        "[IED_-_EAD_-_ISLI1]_Important_:_Campagne_d'inscription_=C3?=  =?iso-8859-1?Q?=A0_l'IED?=\r\n",
        "[IED_-_EAD_-_ISLI1]_Campagne_d'inscription_=C3=A0_l'IED_-_?=  =?iso-8859-1?Q?Ouverture_le_17_juillet_2014?=\r\n",
        "[IED_-_EAD_-_ELI000]_Fin_de_l'ann=C3=A9e_et_deuxi=C3=A8me_?=  =?iso-8859-1?Q?session?=\r\n",
        "tutor=E9?=\r\n",
        "[IED_-_EAD_-_ISLI1]_IMPORTANT_-_Votre_r=C3=A9inscription_?=  =?iso-8859-1?Q?=C3=A0_l'IED?=\r\n",
        "[IED_-_EAD_-_ISLI1]_Message_de_la_Biblioth=C3=A8que_Univer?=  =?iso-8859-1?Q?sitaire_de_Paris_8?=\r\n",
        "Lettre_des_Carnets_du_Centre_Chine_juillet-ao=FBt_2014?=\r\n",
        "Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_2)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_3)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_4)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_du_C?=\r\n=?ISO-8859-15?Q?entre_Chine_(Octobre/Novembre,_n=B0_5)?=\r\n",
        "Re:_Devoir_1=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_6)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_du_Centre_Chine_(No?=\r\n=?ISO-8859-15?Q?vembre,_n=B0_6)_=3D_ANNULE_ET_REMPLACE_L'ENVOI_PRECEDENT?=\r\n",
        "Re:_Devoir_1=A0/_Architecture_des_ordinateurs?=\r\n",
        "Re:_Devoir_2=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Novembre,_n=B0_7?=\r\n",
        "[IED_-_EAD_-_ELI000]_Cours_de_M=C3=A9thodologie_et_documen?=  =?iso-8859-1?Q?tation_1=C3=A8re_ann=C3=A9e_Tr=C3=A8s_important?=\r\n",
        "[IED_-_EAD_-_ELI000]_Les_tuteurs_sont_l=C3=A0_pour_vous_!?=\r\n",
        "s=E9minaire_mardi_25_nov=2E?=\r\n",
        "Re:_Devoir_3=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_8)?=\r\n",
        "=AB_Les_services_aux_chercheurs_:_innovatio?=\r\n=?ISO-8859-15?Q?ns,_=E9volutions,_nouvelles_interactions_=BB,?=\r\n",
        "Re:_Devoir_4=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_9)?=\r\n",
        "Re:_Devoir_5=A0/_Architecture_des_ordinateurs?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_10)?=\r\n",
        "[IED_-_EAD_-_EDF3SA1A]_D=C3=A9but_du_cours_Structures_de_d?=  =?iso-8859-1?Q?onn=C3=A9es_et_Algorithmique_1?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_11)?=\r\n",
        "[IED_-_EAD_-_ISLI1]_Enqu=C3=AAte_des_publics_aupr=C3=A8s_d?=  =?iso-8859-1?Q?es_=C3=A9tudiants_de_l'IED_du_15_d=C3=A9cembre_2014_au_20_?=  =?iso-8859-1?Q?janvier_2015?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_12)?=\r\n",
        "[IED_-_EAD_-_EDF3SA1A]_Impl=C3=A9mentation_d'une_interface?=  =?iso-8859-1?Q?_graphique?=\r\n",
        "conf=E9rence_Zhao_Bing?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_6)?=\r\n",
        "Le_Sage_et_le_peuple._Le_renouveau_confuc=E9en_en_Chine?=\r\n",
        "Pr=E9sences_chinoises_en_Afrique?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_7)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_8)?=\r\n",
        "[IED_-_EAD_-_EDF3CNDA]_\"Du_continu_au_discret\",_changement?=  =?iso-8859-1?Q?_de_cours_et_d'intitul=C3=A9:?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_du_?=\r\n=?ISO-8859-15?Q?Centre_Chine_(F=E9vrier-Mars_2015,_9)?=\r\n",
        "Lettre_hebdomadaire_des_Carnets_du_?=\r\n=?ISO-8859-15?Q?Centre_Chine_(F=E9vrier-Mars_2015,_10)?=\r\n",
        "[IED_-_EAD_-_ELI000]_Probl=C3=A8me_de_mail_ALERTE?=\r\n",
        "[IED_-_EAD_-_EDF4SNMA]_Support_de_cours_-_Syst=C3=A8me_ner?=  =?iso-8859-1?Q?veux_et_fonctions_motrices?=\r\n",
        "[IED_-_EAD_-_ELI000]_Rentr=C3=A9e?=\r\n",
    };

//     vector<string> qp_subjects = {
//         "=?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement?=\r\n",
//         "=?UTF-8?Q?Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver?=\r\n",
//         "=?UTF-8?Q?FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration?=\r\n",
//         "=?UTF-8?Q?Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique?=\r\n",
//         "=?UTF-8?Q?Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique?=\r\n",
//         "=?UTF-8?Q?Marc_:_Fitnessboutique_souhaite_conna=C3=AEtre_votre_avis?=\r\n",
//         "=?utf-8?Q?Re:_P=C3=A9pite?=\r\n",
//         "=?UTF-8?Q?Confirmation_pour_votre_voyage_?=\r\n=?UTF-8?Q?PARIS_-_RENNES,_aller_le_22_ao=C3=BBt?=\r\n",
//         "=?UTF-8?Q?Fwd=3A_Michel_Boujenah_furax_d=27=C3=AAtre_=C2=ABle_juif=2Dtunisie?=\r\n=?UTF-8?Q?n_de_service=C2=BB?=\r\n",
//         "=?UTF-8?Q?Pr=C3=AAt(e)_pour_votre_covoiturage_vers_Pau_=3F?=\r\n",
//         "=?utf-8?Q?Une_autre_r=C3=A9colte_?=\r\n",
//         "=?utf-8?Q?Re:_Une_autre_r=C3=A9colte?=\r\n",
//         "=?UTF-8?Q?Confirmation_pour_votre_voyage_?=\r\n=?UTF-8?Q?RENNES_-_PARIS,_aller_le_16_ao=C3=BBt?=\r\n",
//         "=?utf-8?Q?Confirmation_de_votre_r=C3=A9servation?=\r\n",
//         "=?utf-8?Q?Re:_Kiffe-moi_=C3=A7a?=\r\n",
//         "=?UTF-8?Q?Votre=20dernier=20contact=20avec=20AIR=20FRANCE?=\r\n",
//         "=?UTF-8?Q?Confirmation_pour_votre_voyage_P?=\r\n=?UTF-8?Q?ARIS_-_LORIENT,_aller_le_23_ao=C3=BBt?=\r\n",
//         "=?utf-8?Q?Etats-Unis:_Elle_porte_plainte_contre_une_clinique_apr?=\r\n=?utf-8?Q?=C3=A8s_avoir_accouch=C3=A9_d'un_b=C3=A9b=C3=A9_m?=\r\n=?utf-8?Q?=C3=A9tis?=\r\n",
//         "=?UTF-8?Q?Votre_voyage_=C3=A0_Wuhan_le_23/09/2015_avec_Air_France?=\r\n",
//         "=?UTF-8?Q?Re:_Rentr=C3=A9e?=\r\n",
//         "=?UTF-8?Q?MaribolHD_vous_suit_=C3=A0_pr=C3=A9sent_sur_Twitch?=\r\n",
//         "=?UTF-8?Q?Important_!_Compl=C3=A9tez_votre_dossier_p?= =?UTF-8?Q?our_votre_vol_du_23/09/2015_vers_Wuhan?=\r\n",
//         "=?UTF-8?Q?Re:_Rentr=C3=A9e?=\r\n",
//         "=?utf-8?Q?Re:_Non,_mais_l=C3=A0,_c'est_chaud?=\r\n",
//         "=?utf-8?q?Re:_Ann=C3=A9e_2015-2016?=\r\n",
//         "=?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Compte_activ=C3=A9?=\r\n",
//         "=?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement?=\r\n",
//         "=?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Rentr=C3=A9e?=\r\n",
//     "Subject: =?ISO-8859-1?B?QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
//         "Subject: =?ISO-8859-1?B?QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
//         "Subject: =?UTF-8?B?UmU6IFDDqXBpdGU=?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Exercices_Alg=E8bre_de_Boole?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_EQUIVALENCES=C2=A0:_CETTE_ANNONCE_S'AD?=  =?iso-8859-1?Q?RESSE_UNIQUEMENT_AUX_PRIMO-INSCRITS.?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re=3A_Calcul_des_pr=E9dicats?=\r\n",
//         "Subject: =?iso-8859-1?Q?l=27id=E9e?= =?iso-8859-1?Q?_?=\r\n=?iso-8859-1?Q?int=E9ressante?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Rappel_:_fin_de_la_premi=C3=A8re_sess?=  =?iso-8859-1?Q?ion?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_Important_:_Campagne_d'inscription_=C3?=  =?iso-8859-1?Q?=A0_l'IED?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_Campagne_d'inscription_=C3=A0_l'IED_-_?=  =?iso-8859-1?Q?Ouverture_le_17_juillet_2014?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Fin_de_l'ann=C3=A9e_et_deuxi=C3=A8me_?=  =?iso-8859-1?Q?session?=\r\n",
//         "Subject: Projet =?ISO-8859-1?Q?tutor=E9?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_IMPORTANT_-_Votre_r=C3=A9inscription_?=  =?iso-8859-1?Q?=C3=A0_l'IED?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_Message_de_la_Biblioth=C3=A8que_Univer?=  =?iso-8859-1?Q?sitaire_de_Paris_8?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_des_Carnets_du_Centre_Chine_juillet-ao=FBt_2014?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_2)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_3)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Octobre,_n=B0_4)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_du_C?=\r\n=?ISO-8859-15?Q?entre_Chine_(Octobre/Novembre,_n=B0_5)?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_1=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_6)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_du_Centre_Chine_(No?=\r\n=?ISO-8859-15?Q?vembre,_n=B0_6)_=3D_ANNULE_ET_REMPLACE_L'ENVOI_PRECEDENT?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_1=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_2=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets?=\r\n=?ISO-8859-15?Q?_du_Centre_Chine_(Novembre,_n=B0_7?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Cours_de_M=C3=A9thodologie_et_documen?=  =?iso-8859-1?Q?tation_1=C3=A8re_ann=C3=A9e_Tr=C3=A8s_important?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Les_tuteurs_sont_l=C3=A0_pour_vous_!?=\r\n",
//         "Subject: =?iso-8859-1?Q?s=E9minaire_mardi_25_nov=2E?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_3=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_8)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?=AB_Les_services_aux_chercheurs_:_innovatio?=\r\n=?ISO-8859-15?Q?ns,_=E9volutions,_nouvelles_interactions_=BB,?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_4=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(Novembre,_n=B0_9)?=\r\n",
//         "Subject: =?ISO-8859-1?Q?Re:_Devoir_5=A0/_Architecture_des_ordinateurs?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_10)?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_EDF3SA1A]_D=C3=A9but_du_cours_Structures_de_d?=  =?iso-8859-1?Q?onn=C3=A9es_et_Algorithmique_1?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_11)?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ISLI1]_Enqu=C3=AAte_des_publics_aupr=C3=A8s_d?=  =?iso-8859-1?Q?es_=C3=A9tudiants_de_l'IED_du_15_d=C3=A9cembre_2014_au_20_?=  =?iso-8859-1?Q?janvier_2015?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(D=E9cembre,_n=B0_12)?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_EDF3SA1A]_Impl=C3=A9mentation_d'une_interface?=  =?iso-8859-1?Q?_graphique?=\r\n",
//         "Subject: =?iso-8859-1?Q?conf=E9rence_Zhao_Bing?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_6)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Le_Sage_et_le_peuple._Le_renouveau_confuc=E9en_en_Chine?=\r\n",
//         "Subject: =?iso-8859-1?Q?Pr=E9sences_chinoises_en_Afrique?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_7)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_?=\r\n=?ISO-8859-15?Q?du_Centre_Chine_(F=E9vrier_2015,_8)?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_EDF3CNDA]_"Du_continu_au_discret",_changement?=  =?iso-8859-1?Q?_de_cours_et_d'intitul=C3=A9:?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_du_?=\r\n=?ISO-8859-15?Q?Centre_Chine_(F=E9vrier-Mars_2015,_9)?=\r\n",
//         "Subject: =?ISO-8859-15?Q?Lettre_hebdomadaire_des_Carnets_du_?=\r\n=?ISO-8859-15?Q?Centre_Chine_(F=E9vrier-Mars_2015,_10)?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Probl=C3=A8me_de_mail_ALERTE?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_EDF4SNMA]_Support_de_cours_-_Syst=C3=A8me_ner?=  =?iso-8859-1?Q?veux_et_fonctions_motrices?=\r\n",
//         "Subject: =?iso-8859-1?Q?[IED_-_EAD_-_ELI000]_Rentr=C3=A9e?=\r\n",
//     };

    for (unsigned int i = 0; i < qp_subjects.size(); ++i) {
//         cout << "to decode: " << qp_subjects[i] << "\n"
        cout << "decoded  : " << from_qp(qp_subjects[i], true)
             << endl;
    }

    cout << from_hex_string("=C3=A9") << endl;

    return 0;
}

#endif
