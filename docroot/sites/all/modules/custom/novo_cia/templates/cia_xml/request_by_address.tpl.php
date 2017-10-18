<?php

/**
 * @file
 * Cia request by address theme.
 */
?>

<?php print '<?xml version="1.0" encoding="UTF-8"?>'; ?>
<NewRequest>
    <Login>
        <UserName><?php print $username; ?></UserName>
        <Password><?php print $password; ?></Password>
    </Login>
    <source>VolunteerApp</source>
    <Client>
        <ClientName><?php print $client_name;?></ClientName>
        <BranchName><?php print $branch_name;?></BranchName>
        <ClientContact><?php print $client_contact;?></ClientContact>
        <ClientContactEmail><?php print $client_contact_email;?></ClientContactEmail>
    </Client>

    <BackgroundCheck>
        <Subject>
            <FirstName><?php print $first_name;?></FirstName>
            <MiddleInitial><?php print $middle_initial;?></MiddleInitial>
            <LastName><?php print $last_name; ?></LastName>
            <AliasFirstName><?php print $alias_first_name; ?></AliasFirstName>
            <AliasLastName><?php print $alias_last_name; ?></AliasLastName>
            <Suffix><?php print $suffix; ?></Suffix>
            <Address><?php print $address; ?></Address>
            <City><?php print $city;?></City>
            <State><?php print $state; ?></State>
            <ZipCode><?php print $zip_code;?></ZipCode>
            <DOB>
                <DOBYEAR><?php print $dob['year'];?></DOBYEAR>
                <DOBMONTH><?php print $dob['month'];?></DOBMONTH>
                <DOBDAY><?php print $dob['day'];?></DOBDAY>
            </DOB>
        </Subject>

        <Search>
            <Type>Social Security Trace</Type>
            <AcceptDuplicate>True</AcceptDuplicate>
            <OrderMore>Y</OrderMore>
            <RefNumber><?php print $ref_number; ?></RefNumber>
        </Search>
    </BackgroundCheck>
</NewRequest>
