async function update() {
    let celsius = document.getElementById('celsius').checked;
    let lat = document.getElementById('lat').value;
    let long = document.getElementById('long').value;

    if (lat == '' || long == '') {
        document.getElementById('Currently').innerHTML ='You have not enterd any coordinates';
        return;
    }

    let http = new XMLHttpRequest();
    
    http.onreadystatechange = function() {
        document.getElementById('Currently').innerHTML = 'loading...';
        let response = this.responseText;
        document.getElementById('Currently').innerHTML = response;
    }

    let string = '/weather?lat=' + lat + '&long=' + long;

    if (!celsius) {
        string += '&celsius=false'
    }

    await http.open('GET', string, true);
    await http.send();
}
