#include "coding.hpp"

string
mmdecode(string s, bool is_hdr)
{
    string res;
    string charset;
    string encoding;
    string enc_word;
    bool is_parsing_charset = false;
    bool is_parsing_encoding = false;
    bool is_parsing_enc_word = false;

    for (unsigned int i = 0; i < s.length(); i++) {

        if (s[i] == '=') {
            if (!is_parsing_enc_word) {
                if (s[i+1] == '?') {
                    is_parsing_charset = true;
                    i += 2;
                }
                else if (s[i+1] == '\r') {
                    i += 3;
                    continue;
                }
            }
        }

        if (s[i] == '?') {
            if (is_parsing_charset) {
                is_parsing_encoding = true;
                is_parsing_charset = false;
                i += 1;
            }
            else if (is_parsing_encoding) {
                is_parsing_encoding = false;
                is_parsing_enc_word = true;
                i += 1;
            }
            else if (is_parsing_enc_word) {
                if (s[i+1] == '=') {
                    is_parsing_enc_word = false;
                    i += 1;
                }
            }
        }

        if (is_parsing_charset) {
            charset += s[i];
        }
        else if (is_parsing_encoding) {
            encoding += s[i];
        }
        else if (is_parsing_enc_word) {
            enc_word += s[i];
        }
        else {
            if (enc_word.length() > 0) {
                if (encoding == "Q" || encoding == "q") {
                    res += qp::from_qp(enc_word);
                }
                else if (encoding == "B" || encoding == "b") {
                    res += base64::from_base64(enc_word);
                }

#ifdef CODING_DEBUG
                cout << "charset: " << charset << endl;
                cout << "encoding: " << encoding << endl;
                cout << "enc_word: " << enc_word << endl;
#endif

                charset.clear();
                encoding.clear();
                enc_word.clear();
            }
            else {
                res += s[i];
            }
        }
    }

    if (is_hdr) {
        for (unsigned int i = 0; i < res.length(); i++) {
            if (res[i] == '_')
                res[i] = ' ';
        }
    }

    return res;
}

#ifdef CODING_DEBUG

#include <vector>

int
main()
{
    vector<string> plain_subjects = {
        "Subject: Confirmation de commande  BFN721693\r\n",
        "Subject: Confirmation de votre inscription\r\n",
        "Subject: Complete Registration With Stack Exchange\r\n",
        "Subject: Share your knowledge with the Stack Overflow community.\r\n",
        "Subject: Votre nouveau mot de passe\r\n",
        "Subject: Enregistrement d'un pseudo (asm)\r\n",
        "Subject: Bienvenue chez Cdiscount\r\n",
        "Subject: Your Steam account: Email address change request\r\n",
        "Subject: Thank you for your purchase!\r\n",
        "Subject: [GitHub] Please verify your email address.\r\n",
        "Subject: asm99 + GitHub = <3\r\n",
        "Subject: Ken remix\r\n",
        "Subject: Re: Ken remix\r\n",
        "Subject: Re: Ken remix\r\n",
        "Subject: Confirmation pour vos voyages : 1/ RENNES - BORDEAUX, 2/ BORDEAUX -\r\nPARIS\r\n",
        "Subject: Petit matin!\r\n",
        "Subject: Eleven\r\n",
        "Subject: Yo des news ?\r\n",
        "Subject: Re: Yo des news ?\r\n",
        "Subject: Regarder \"Funniest Moment / Biggest Fail of Evo 2015 (Guilty Gear Xrd\r\n-SIGN- Semis)\" sur YouTube\r\n",
        "Subject: Re: Regarder \"Funniest Moment / Biggest Fail of Evo 2015 (Guilty Gear\r\nXrd -SIGN- Semis)\" sur YouTube\r\n",
        "Subject: Re: Yo des news ?\r\n",
        "Subject: Re: Regarder \"Funniest Moment / Biggest Fail of Evo 2015 (Guilty Gear\r\nXrd -SIGN- Semis)\" sur YouTube\r\n",
        "Subject: Re: Yo des news ?\r\n",
        "Subject: Envoi de l'ordre de mission\r\n",
        "Subject: Actualisation des offres : secteur Centre-Bretagne et Pays de la Loire\r\n",
        "Subject: REMPLACEMENT SEPTEMBRE / OCTOBRE EN VENDEE\r\n",
        "Subject: Agathe\r\n",
        "Subject: Confirmation de paiement\r\n",
        "Subject:  Votre facture Numericable chez Greenbureau\r\n",
        "Subject: freenode Account Registration\r\n",
        "Subject: Your Twitch password\r\n",
        "Subject: Re: Microsoft\r\n",
        "Subject: Cher Monsieur Marc Melkonian: Billet et informations pour votre voyage du  23/09/2015\r\n",
        "Subject: Impression facture  (xmedia ref:263331382)\r\n",
        "Subject: Impression facture  (xmedia ref:263331451)\r\n",
        "Subject: Marc : un cadeau vous attend sur FitnessBoutique.fr\r\n",
        "Subject: Confirmation pour votre voyage RENNES - ROISSY, aller le 23 sept.,\r\nretour le 22 oct.\r\n",
        "Subject: OFFRES DE REMPLACEMENT /  MEDECIN GENERALISTE EN BRETAGNE\r\n",
        "Subject: Re: Microsoft\r\n",
        "Subject: Confirmation pour votre voyage RENNES - PARIS, aller le 01 sept.\r\n",
        "Subject: Steam Account Password Reset\r\n",
        "Subject: Recent changes to your Steam account\r\n",
        "Subject: Your Steam account: Family View activation\r\n",
        "Subject: Broooo \r\n",
        "Subject: Re: News\r\n",
        "Subject: Votre justificatif de voyage RENNES - PARIS du 01/09/2015 \r\n",
        "Subject:  Votre facture Numericable chez Greenbureau\r\n",
        "Subject: Envoi de l'ordre de mission\r\n",
        "Subject: Envoi de l'ordre de mission\r\n",
        "Subject: Confirmation pour votre voyage PARIS - RENNES, aller le 07 sept.,\r\nretour le 08 sept.\r\n",
        "Subject: [GitHub] Please reset your password\r\n",
        "Subject: [GitHub] Your password has changed\r\n",
        "Subject: remplacement en SSR site de NOZAY\r\n",
        "Subject: OFFRE TRAIN : PARIS - RENNES et bien d'autres trajets a petits prix avec TGV ou INTERCITES !\r\n",
        "Subject: Confirmation pour votre voyage PARIS - RENNES, aller le 13 sept.\r\n",
        "Subject: Votre justificatif de voyage RENNES - PARIS du 08/09/2015 \r\n",
        "Subject: Carte grise\r\n",
        "Subject: Wesh\r\n",
        "Subject: Re: Adresse\r\n",
        "Subject: Proposition de remplacement\r\n",
        "Subject: Fwd: Bulletin\r\n",
        "Subject: Actualisation des offres : Secteur Bretagne-Pays de la Loire et Poitou\r\ncharentes\r\n",
        "Subject: Re: Wesh\r\n",
        "Subject: Thank you for your purchase!\r\n",
        "Subject: RE:Bleeding Drugs Review\r\n",
        "Subject: Enregistrez-vous en ligne pour votre voyage vers Wuhan du 23/09/2015\r\n",
        "Subject: Cartes d'embarquement\r\n",
        "Subject: Remplacement du 28/09 au 16/09\r\n",
        "Subject: Re: Faut aimer les contres commerciaux\r\n",
        "Subject: I2CAL VPC           : Ticket Paiement\r\n",
        "Subject: [www.didactibook.com] Commande no. IZ1443263028.6265.40041 - Confirmation\r\n",
        "Subject: RE:RE:Bleeding Drugs Review\r\n",
        "Subject: Re: James Bond\r\n",
        "Subject: PETITS PRIX TRAIN : decouvrez nos meilleures offres dans un espace dedie !\r\n",
        "Subject: [GitHub] Please reset your password\r\n",
        "Subject: [GitHub] Your password has changed\r\n",
        "Subject: Welcome to Ekiga.net!\r\n",
        "Subject: www.diamondcard.us Sales Receipt 105707822340\r\n",
        "Subject: Contact Page Submission\r\n",
        "Subject: Pending Credit Card order\r\n",
        "Subject: Diamond Worldwide Communication Service Signup Confirmation\r\n",
        "Subject: Your new account on xmpp.zone\r\n",
        "Subject: Diamondcard.us Order #105133 Update\r\n",
        "Subject: [GitHub] Please reset your password\r\n",
        "Subject: [GitHub] Your password has changed\r\n",
        "Subject: Re: Test\r\n",
    };

    vector<string> qp_subjects = {
        "Subject: =?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement?=\r\n",
        "Subject: =?UTF-8?Q?Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver?=\r\n",
        "Subject: =?UTF-8?Q?FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration?=\r\n",
        "Subject: =?UTF-8?Q?Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique?=\r\n",
        "Subject: =?UTF-8?Q?Marc_:_Vous_avez_gagn=C3=A9_59_points_sur_FitnessBoutique?=\r\n",
        "Subject: =?UTF-8?Q?Marc_:_Fitnessboutique_souhaite_conna=C3=AEtre_votre_avis?=\r\n",
        "Subject: =?utf-8?Q?Re:_P=C3=A9pite?=\r\n",
        "Subject: =?UTF-8?Q?Confirmation_pour_votre_voyage_?=\r\n=?UTF-8?Q?PARIS_-_RENNES,_aller_le_22_ao=C3=BBt?=\r\n",
        "Subject: =?UTF-8?Q?Fwd=3A_Michel_Boujenah_furax_d=27=C3=AAtre_=C2=ABle_juif=2Dtunisie?=\r\n=?UTF-8?Q?n_de_service=C2=BB?=\r\n",
        "Subject: =?UTF-8?Q?Pr=C3=AAt(e)_pour_votre_covoiturage_vers_Pau_=3F?=\r\n",
        "Subject: =?utf-8?Q?Une_autre_r=C3=A9colte_?=\r\n",
        "Subject: =?utf-8?Q?Re:_Une_autre_r=C3=A9colte?=\r\n",
        "Subject: =?UTF-8?Q?Confirmation_pour_votre_voyage_?=\r\n=?UTF-8?Q?RENNES_-_PARIS,_aller_le_16_ao=C3=BBt?=\r\n",
        "Subject: =?utf-8?Q?Confirmation_de_votre_r=C3=A9servation?=\r\n",
        "Subject: =?utf-8?Q?Re:_Kiffe-moi_=C3=A7a?=\r\n",
        "Subject: =?UTF-8?Q?Votre=20dernier=20contact=20avec=20AIR=20FRANCE?=\r\n",
        "Subject: =?UTF-8?Q?Confirmation_pour_votre_voyage_P?=\r\n=?UTF-8?Q?ARIS_-_LORIENT,_aller_le_23_ao=C3=BBt?=\r\n",
        "Subject: =?utf-8?Q?Etats-Unis:_Elle_porte_plainte_contre_une_clinique_apr?=\r\n=?utf-8?Q?=C3=A8s_avoir_accouch=C3=A9_d'un_b=C3=A9b=C3=A9_m?=\r\n=?utf-8?Q?=C3=A9tis?=\r\n",
        "Subject: =?UTF-8?Q?Votre_voyage_=C3=A0_Wuhan_le_23/09/2015_avec_Air_France?=\r\n",
        "Subject: =?UTF-8?Q?Re:_Rentr=C3=A9e?=\r\n",
        "Subject: =?UTF-8?Q?MaribolHD_vous_suit_=C3=A0_pr=C3=A9sent_sur_Twitch?=\r\n",
        "Subject: =?UTF-8?Q?Important_!_Compl=C3=A9tez_votre_dossier_p?= =?UTF-8?Q?our_votre_vol_du_23/09/2015_vers_Wuhan?=\r\n",
        "Subject: =?UTF-8?Q?Re:_Rentr=C3=A9e?=\r\n",
        "Subject: =?utf-8?Q?Re:_Non,_mais_l=C3=A0,_c'est_chaud?=\r\n",
        "subject: =?utf-8?q?Re:_Ann=C3=A9e_2015-2016?=\r\n",
        "Subject: =?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Compte_activ=C3=A9?=\r\n",
        "Subject: =?utf-8?Q?=5Bwww=2Edidactibook=2Ecom=5D_Commande_no=2E_IZ=31=34=34=33=32=36=33=30=32=38=2E=36=32=36=35=2E=34=30=30=34=31_=2D_Liens_de_t=C3=A9l=C3=A9chargement?=\r\n",
    };

    vector<string> b64_subjects = {
        "Subject: =?ISO-8859-1?B?QmlsbGV0IOlsZWN0cm9uaXF1ZSAtIFZFTEFaUVVFWiAtIEJJTExFVCBTSU1QTEUgLSBDb25maXJtYXRpb24gZGUgbCdhY2hhdA==?=\r\n",
        "Subject: =?UTF-8?B?UmU6IFDDqXBpdGU=?=\r\n",
        "Subject: =?UTF-8?B?UmU6IFDDgyhjKXBpdGU=?=\r\n",
        "Subject: =?UTF-8?B?UmU6IEZ3ZDogTWljaGVsIEJvdWplbmFoIGZ1cmF4IGQnw4PCqnRyZSDDgsKrbGUganVpZg==?=\r\n=?UTF-8?B?LXR1bmlzaWVuIGRlIHNlcnZpY2XDgsK7?=\r\n",
        "Subject: =?utf-8?B?T3Bwb3J0dW5pdMOpIHByb2Zlc3Npb25uZWxsZSBlbiBDREkgLSBNw6lkZWNpbiBNUFIgSC9GIC0gw6AgcHJveGltaXTDqSBkZSBSZW5uZXMgKDM1KQ==?=\r\n",
        "Subject: =?utf-8?B?T3Bwb3J0dW5pdMOpIHByb2Zlc3Npb25uZWxsZSAtIENESSAtIEJyZXRhZ25l?=\r\n",
        "Subject: =?utf-8?B?RW52b2kgZGUgbCdvcmRyZSBkZSBtaXNzaW9uIDogTXV0dWFsaXTDqSBGcmFuw6dhaXNl?=\r\n",
        "Subject: =?UTF-8?B?UmU6IEtpZmZlLW1vaSDDp2E=?=\r\n",
        "Subject: =?utf-8?B?UmVtcGxhY2VtZW50cyBBb8O7dCAtIEFwcGVsIE3DqWRpY2FsIFNlYXJjaA==?=\r\n",
        "Subject: =?utf-8?B?UHJvcG9zaXRpb24gZGUgcmVtcGxhY2VtZW50cyBhb8O7dCDDoCBvY3RvYnJlIDIwMTUgLSBBcHBlbCBNw6lkaWNhbCBTZWFyY2g=?=\r\n",
        "Subject: =?utf-8?B?VVJHRU5UOiByZWNoZXJjaGUgbcOpZGVjaW4gZ8OpcmlhdHJlL2fDqW7DqXJhbGlzdGUgKDI4KQ==?=\r\n",
        "Subject: =?utf-8?B?TcOpZGVjaW5zIGfDqW7DqXJhbGlzdGUgZW4gQnJldGFnbmUgc2VwdGVtYnJlIG9jdG9icmUgbm92ZW1icmU=?=\r\n",
        "Subject: =?utf-8?B?Q0REIE3DqWRlY2luIEfDqW7DqXJhbGlzdGUgb3UgTVBSIGgtZg==?=\r\n",
        "Subject: =?utf-8?B?T3Bwb3J0dW5pdMOpIC0gTcOpZGVjaW4gY29vcmRvbm5hdGV1ciBoLWYgbWkgdGVtcHMgY2RpIC0gQ2hhbXBhZ25lIEFyZGVubmVz?=\r\n",
        "Subject: =?utf-8?B?UHJvcG9zaXRpb24gcmVtcGxhY2VtZW50cyAtIEFwcGVsIE3DqWRpY2FsIFNlYXJjaA==?=\r\n",
        "Subject: =?UTF-8?B?Tm9uLCBtYWlzIGzDoCwgYydlc3QgY2hhdWQ=?=\r\n",
        "Subject: =?utf-8?B?UmVtcGxhY2VtZW50cyDDoCBwb3Vydm9pciAtIEFwcGVsIE3DqWRpY2FsIFNlYXJjaA==?=\r\n",
        "Subject: =?utf-8?B?VVJHRU5UICEgTm91cyBhdm9ucyB1bmUgb2ZmcmUgZGUgTUVERUNJTiBHRU5FUkFMSVNURSBBIEFSQ0FDSE9OICgzMykgw6AgcGFydGlyIGR1IDA5LzEwLzIwMTU=?=\r\n",
        "Subject: =?utf-8?B?Q0RJIE3DqWRlY2luIGRlIHJlY2hlcmNoZSBjbGluaXF1ZSBlbiBCcmV0YWduZQ==?=\r\n",
        "Subject: =?utf-8?B?TOKAmUFwcGVsIG3DqWRpY2FsIHNlYXJjaCByZWNoZXJjaGUgcG91ciBzZXMgY2xpZW50cyBkZXMgbcOpZGVjaW5zIGfDqW7DqXJhbGlzdGVzIGgtZg==?=\r\n",
        "Subject: =?utf-8?B?TWlzZSDDoCBqb3VyIGRlIHZvcyBkaXNwb25pYmlsaXTDqXMgLSBBcHBlbCBNw6lkaWNhbCBTZWFyY2g=?=\r\n",
        "Subject: =?utf-8?B?TWVyY2kgZOKAmcOpdmFsdWVyIHZvdHJlIHZvbCBBaXIgRnJh?=\r\n=?utf-8?B?bmNlIGRlIFBhcmlzLCBDaGFybGVzIGRlIEdhdWxsZSAoQ0RHKSDDoCBX?=\r\n=?utf-8?B?dWhhbiwgVGlhbmhlIEludGVybmF0aW9uYWwgKFdVSCk=?=\r\n",
        "Subject: =?utf-8?B?UmVtcGxhY2VtZW50cyDDoCBwb3Vydm9pciAtIEFwcGVsIE3DqWRpY2FsIFNlYXJjaA==?=\r\n",
        "Subject: =?utf-8?B?Tm91dmVsbGVzIG9wcG9ydHVuaXTDqXMgcHJvZmVzc2lvbm5lbGxlcyAtIENESSAtIFBheXMgZGUgTG9pcmUvQnJldGFnbmU=?=\r\n",
        "Subject: =?utf-8?B?Tm91dmVhdXggcmVtcGxhY2VtZW50cyDDoCBwb3Vydm9pciAtIEFwcGVsIE3DqWRpY2FsIFNlYXJjaA==?=\r\n",
        "Subject: =?utf-8?B?RGlmZnVzaW9uIHLDqXNlYXU=?=\r\n",
    };

    vector<vector<string>> vec = {
        plain_subjects,
        b64_subjects,
        qp_subjects,
    };

    for (unsigned int i = 0; i < vec.size(); i++) {
        vector<string>& v = vec[i];

        for (unsigned int j = 0; j < v.size(); j++) {
            cout << "to decode: " << v[j]
                 << "decoded  : " << mmdecode(v[j], true) << "\n"
                 << endl;
        }
    }

    return 0;
}
#endif

