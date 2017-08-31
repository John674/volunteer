<?php

/**
 * @file
 * Cia query report theme.
 */
?>

<?php print '<?xml version="1.0" encoding="UTF-8"?>'; ?>
<QueryRequest>
    <Login>
        <UserName><?php print $username; ?></UserName>
        <Password><?php print $password; ?></Password>
    </Login>
    <Client>
        <ClientName><?php print $client_name;?></ClientName>
        <BranchName><?php print $branch_name;?></BranchName>
        <ClientContact><?php print $client_contact;?></ClientContact>
        <ClientContactEmail><?php print $client_contact_email;?></ClientContactEmail>
    </Client>
    <QueryIDs>
        <TrackingNumber><?php print $tracking_number;?></TrackingNumber>
    </QueryIDs>
</QueryRequest>