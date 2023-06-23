# Smart-solar-panel-with-arduino
Ξεκινώντας με το start simulation οι σερβοκινητήρες παίρνουν τις αρχικές τιμές που  έχουμε δώσει μέσα από τον κώδικα που δημιουργήσαμε. Πατώντας το button (δουλεύει σαν  είσοδος στο κύκλωμα στο D7) ενεργοποιείται η αυτόματη λειτουργία (ανάβει το πράσινο led οπού δουλεύει σαν έξοδος στο κύκλωμα D11) οπού οι σερβοκινητήρες λαμβάνουν κίνηση  μέσω των αισθητήρων φωτός που έχουμε τοποθετήσει. Οι φωτοαντιστάσεις έχουν τοποθετηθεί κατάλληλα, ώστε να μπορούν να διακρίνουν προς ποια κατεύθυνση υπάρχει μεγαλύτερη  ηλιακή ενέργεια (έχουν συνδεθεί με τα αναλογικά σήματα του Arduino και λειτουργούν ως  είσοδοι). Το σήμα που παίρνουν οι φωτοαντιστάσεις, εξαρτάται από το ποσοστό του φωτός  που πέφτει επάνω σε αυτές. Στη συνέχεια, το σήμα που λαμβάνουν, πηγαίνει στο αναλογικό  σήμα του Arduino και από εκεί μετατρέπεται σε ψηφιακό. Το μεταβαλλόμενο αυτό σήμα, δίνει  τελικά την ανάλογη κίνηση στους σερβοκινητήρες. Οι αντιστάσεις που είναι τοποθετημένες σε  κάθε ξεχωριστό κομμάτι του κυκλώματος, έχουν μπει για να ελέγχουν την διέλευση του ηλεκτρικού ρεύματος για κάθε αγωγό. Πατώντας 2η φορά το button, ενεργοποιείται η χειροκίνητη λειτουργία (ανάβει το κόκκινο led, που δουλεύει σαν έξοδος στο κύκλωμα D12)  και η κίνηση των κινητήρων του κυκλώματος, εξαρτάται από τα 2 ποτενσιόμετρα. Το ποτενσιόμετρο που βλέπουμε από τη δεξιά πλευρά, κινεί το ηλιακό πάνελ δεξιόστροφα και αριστερόστροφα, δηλαδή κινεί τον κινητήρα με οριζόντια κίνηση (λειτουργεί στο κύκλωμα ως είσοδος στο αναλογικό σήμα A0). Το ποτενσιόμετρο που βλέπουμε από την αριστερή πλευρά, κινεί το πάνελ πάνω-κάτω δηλαδή κινεί το σερβοκινητήρα με κάθετη κίνηση (λειτουργεί ως είσοδος στο κύκλωμα που είναι συνδεδεμένο στο αναλογικό σήμα του Arduino). Τα ποτενσιόμετρα συνδέονται στο αναλογικό σήμα του Arduino και οι τιμές που δίνουν, μεταβάλλονται ανάλογα με τη ‘’γωνία‘’ που θα τους δώσουμε εμείς χειροκίνητα. Οι τιμές που δίνουν τα ποτενσιόμετρα είναι από 0 έως 1023. Το σήμα αυτό πηγαίνει στις αντίστοιχες αναλογικές θήρες του Arduino, και στη συνέχεια μετατρέπουμε αυτές τις τιμές από 0-1023 σε 0 έως 180 μοίρες. Μετά, το σήμα αυτό πηγαίνει στις ψηφιακές εξόδους του Arduino και κινούνται οι κινητήρες. Οι κινητήρες, δουλεύουν σαν έξοδοι στο κύκλωμα και είναι συνδεδεμένοι σε ψηφιακές θήρες του Arduino και παίρνουν την τροφοδοσία τους μέσω του breadboard. Το breadboard είναι συνδεδεμένο με την τροφοδοσία και τη γείωση του Arduino (5v-GND), κι έτσι έχουμε ένα λιγότερο περίπλοκο κύκλωμα. 
![alt text](https://github.com/Karydis1/Solar-Panel-Automatic/blob/main/Tinkercad.png)
