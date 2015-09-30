/*
 * MELKONIAN Marc
 * IED 13410425
 * RFC822_header: an object to represent an IMAP response to the
 *                "FETCH RFC822.HEADER" command.
 * Note: Fields included in the response are based on the RFC 822 but this
 *       RFC has been extended by numerous other ones.
 *       The list of fields comes from this page:
 *         http://people.dsv.su.se/~jpalme/ietf/ietf-mail-attributes.html
 *       While trying to be exhaustive, please keep in mind that servers
 *       generally don't return all the fields mentioned here and return some
 *       various non-standard other ones.
 * Doc: https://tools.ietf.org/html/rfc2822 (supersedes RFC 822)
 */

#ifndef RFC822_HEADER_H
#define RFC822_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class RFC822_header
{
    private:
        // === RFC 822 ===
        string bcc;		            // "Bcc" ":"
        string cc;		            // "Cc" ":"
        string comments;		    // "Comments" ":"
        string date;		        // "Date" ":"
        string encrypted;		    // "Encrypted" ":"
        string from;		        // "From" ":"
        string in_reply_to;		    // "In-Reply-To" ":"
        string keywords;		    // "Keywords" ":"
        string message_id;		    // "Message-ID" ":"
//         string received;		    // "Received" ":"
		map<string, string> received;	// "Received" ":"
        string references;		    // "References" ":"
        string reply_to;		    // "Reply-To" ":"
        string resent_bcc;		    // "Resent-Bcc" ":"
        string resent_cc;		    // "Resent-Cc" ":"
        string resent_date;		    // "Resent-Date" ":"
        string resent_from;		    // "Resent-From" ":"
        string resent_message_id;	// "Resent-Message-ID" ":"
        string resent_reply_to;		// "Resent-Reply-To" ":"
        string resent_to;		    // "Resent-To" ":"
        string return_path;		    // "Return-Path" ":"
        string sender;		        // "Sender" ":"
        string subject;		        // "Subject" ":"
        string to;		            // "To" ":"

        // extension-field
        // Note: none will have names beginning with the string "X-"
        map<string, string> extension_fields;

        // user-defined-field
        // Note: The prefatory string "X-" will never be used in the names of
        //       Extension-fields. This provides user-defined fields with a
        //       protected set of names.
        map<string, string> user_defined_fields;

		// === RFC 976 ===
// 		"From "			// (followed by space, not colon (:") / non-standard

		// === RFC 1036 ===
// 		Approved		// not standardized for use in e-mail
// 		Control			// only in Usenet News, not in e-mail
// 		Distribution	// not standardized for use in e-mail
// 		Expires			// not standardized for use in e-mail
// 		Followup-To		// not standardized for use in e-mail
// 		Lines			// not standardized for use in e-mail
// 		Newsgroups		// not standardized and controversial for use in e-mail
// 		Organization	// not standardized for use in e-mail
// 		Path			// only in Usenet News, not in e-mail
// 		Summary			// not standardized for use in e-mail, discouraged
// 		Xref			// only in Usenet News, not in e-mail

		// === RFC 1327 ===
// 		Alternate-recipient					// not for general usage
// 		Auto-Forwarded						// not for general usage
// 		Content-Identifier					// not for general usage
// 		Content-Return						// not for general usage
// 		Conversion							// not for general usage
// 		Conversion-With-Loss				// not for general usage
// 		Delivery-Date						// not for general usage
// 		Discarded-X400-IPMS-Extensions		// not for general usage
// 		Discarded-X400-MTS-Extensions		// not for general usage
// 		Disclose-Recipients					// not for general usage
// 		DL-Expansion-History				// not for general usage
// 		Expiry-Date							// not for general usage
// 		Generate-Delivery-Report			// not for general usage
// 		Importance							// experimental
// 		Incomplete-Copy						// not for general usage
// 		Language							// not for general usage
// 		Message-Type Delivery				// not for general usage
// 		Obsoletes							// not for general usage
// 		Original-Encoded-Information-Types	// not for general usage
// 		Prevent-NonDelivery-Report			// not for general usage
// 		Priority							// not for general usage
// 		Reply-By							// not for general usage
// 		Report								// not for general usage
// 		Sensitivity							// experimental

		// === RFC 1505 ===
// 		Encoding							// experimental

		// === RFC 2045 ===
		string content_description;			// "Content-Description" ":"
		string content_id;					// "Content-ID" ":"
		string content_transfer_encoding;	// "Content-Transfer-Encoding" ":"
		string content_type;				// "Content-Type" ":"
		string mime_version;				// "MIME-Version" ":"

		// === RFC 1806 ===
// 		Content-Disposition					// experimental

		// === RFC 1864 ===
// 		Content-MD5							// proposed standard

		// === RFC 2110 ===
		string content_base;				// "Content-Base" ":"
		string content_location;			// "Content-Location" ":"

		// === RFC 2369 === (Mailing list control)
// 		List-Archive
// 		List-Help
// 		List-Owner
// 		List-Post
// 		List-Software
// 		List-Subscribe
// 		List-Unsubscribe

		// son-of-RFC1036 [21]
// 		also-control		// non-standard, only in usenet news, not in e-mail
// 		article-names		// non-standard
// 		article-updates		// non-standard
// 		see-also			// non-standard
// 		supersedes			// non-standard

		// === RFC 2298 ===
		// "Disposition-Notification-To" ":"
		string disposition_notification_to;
		// "Disposition-Notification-Options" ":"
		string disposition_notification_options;
		// "Original-Recipient" ":"
		string original_recipient;

		// World Wide Web Consortium (W3C) Recommendations
// 		Pics-Label

        // Tags inside a "Received" field
        static const vector<string> tags;

	public:
		RFC822_header();
		~RFC822_header();

        // DEBUG
		void dump();
};

#endif /* end of include guard: RFC822_HEADER_H */
