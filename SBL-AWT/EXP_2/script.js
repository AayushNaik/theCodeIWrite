$(document).ready(function() {
    $('#password').on('input', function() {
        var password = $(this).val();
        var strength = checkPasswordStrength(password);

        // Update star rating
        $('.star').removeClass('active');
        for (var i = 0; i < strength; i++) {
            $('.star').eq(i).addClass('active');
        }

        // Update strength text
        var strengthText = getStrengthText(strength);
        $('#strength-text').text(strengthText);
    });

    function checkPasswordStrength(password) {
        var strength = 0;

        // Increase strength if password has more than 8 characters
        if (password.length > 8) strength++;
        
        // Increase strength if password contains lowercase and uppercase letters
        if (/[a-z]/.test(password) && /[A-Z]/.test(password)) strength++;
        
        // Increase strength if password contains numbers
        if (/\d/.test(password)) strength++;
        
        // Increase strength if password contains special characters
        if (/[@$!%*?&#]/.test(password)) strength++;
        
        // Increase strength if password length is more than 12 characters
        if (password.length > 12) strength++;

        return strength;
    }

    function getStrengthText(strength) {
        switch(strength) {
            case 1:
                return 'Very Weak';
            case 2:
                return 'Weak';
            case 3:
                return 'Moderate';
            case 4:
                return 'Strong';
            case 5:
                return 'Very Strong';
            default:
                return '';
        }
    }
});
